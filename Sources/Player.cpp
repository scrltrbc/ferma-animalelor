//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Player.hpp"


Stats Player::get_stats() const {
    return stats;
}

int Player::get_prune() const {
    return prune;
}

Player::Player(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name, int balance, int prune, float speed,
               const std::vector<std::shared_ptr<Item>> &items, const std::vector<std::shared_ptr<Plant>> &plants)
    : Entity(texturePath, pos, name),
          balance(balance),
          prune(prune),
          speed(speed),
          items(items),
          plants(plants) { loadTextures();}

Player::~Player()=default;

void Player::movePlayer(float dt) {
    sf::Vector2f dir(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dir.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dir.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dir.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dir.x += 1;

    if (dir.x != 0 || dir.y != 0) {
        float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        dir /= len;

        updateDirectionTexture(dir);
        get_sprite().move(dir * speed * dt);
    }
}

void Player::loadTextures() {
    texture_left=ResourceManager<sf::Texture>().get("C:/Users/becbu/CLionProjects/ferma-animalelor/cmake-build-debug/Assets/Textures/player_stanga.png");
    texture_right=ResourceManager<sf::Texture>().get("Assets/Textures/player_dreapta.png");
    texture_up=ResourceManager<sf::Texture>().get("Assets/Textures/player_spate.png");
}

void Player::updateDirectionTexture(const sf::Vector2f &dir) {
    if (dir.x == 0 && dir.y == 0)
        return;

    if (std::abs(dir.x) > std::abs(dir.y)) {
        if (dir.x > 0)
            get_sprite().setTexture(*texture_right,true);
        else
            get_sprite().setTexture(*texture_left,true);
    }
    else {
        if (dir.y > 0)
            get_sprite().setTexture(*get_texture(),true);
        else
        get_sprite().setTexture(*texture_up,true);
    }
}

void Player::addPlant(const std::shared_ptr<Plant> &plant) {
    plants.push_back(plant);
}

void Player::removePlant(const std::shared_ptr<Plant> &plant) {
    plants.erase(std::remove(plants.begin(), plants.end(), plant), plants.end());
}

std::vector<std::shared_ptr<Plant>> & Player::getPlants() {
    return plants;
}

void Player::addItem(const std::shared_ptr<Item> &it) {
    if (!hasEffect(it->get_effect()))
        items.push_back(it);
}

int Player::get_balance() const {
    return balance;
}

void Player::set_balance(int val) {
    if (balance<INT_MAX-val)
        balance += val;
    else
        balance=INT_MAX;
}

bool Player::tryPlant(Crop &crop) {
    if (crop.isOccupied())
        return false;

    // find first seed
    for (auto& p : plants) {
        if (p->get_growth()==0) {
            bool boosted = hasEffect(effectType::plantsGrowthBoost);

            if (crop.plantHere(p, boosted)) {
                removePlant(p);
                return true;
            }
        }
    }
    return false;
}

bool Player::tryHarvest(Crop &crop) {
    if (!crop.isReady())
        return false;

    auto harvested = crop.harvest();
    if (!harvested)
        return false;

    addPlant(harvested);

    set_balance(harvested->get_selling_price());
    return true;
}

bool Player::hasEffect(effectType type) {
    for (const auto &i : items)
        if (i->get_effect() == type)
            return true;
    return false;
}
