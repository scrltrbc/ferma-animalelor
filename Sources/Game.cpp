//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Game.hpp"
#include "../Headers/Stats.hpp"

/*
static bool rectsIntersect(const sf::FloatRect& a, const sf::FloatRect& b)
{
    float aLeft = a.position.x;
    float aTop  = a.position.y;
    float aRight = a.position.x + a.size.x;
    float aBottom = a.position.y + a.size.y;

    float bLeft = b.position.x;
    float bTop  = b.position.y;
    float bRight = b.position.x + b.size.x;
    float bBottom = b.position.y + b.size.y;

    return !(aRight <= bLeft || aLeft >= bRight || aBottom <= bTop || aTop >= bBottom);
}*/

//Metode Private
void Game::initWindow() {
    this->window= new sf::RenderWindow(sf::VideoMode({1920u,1080u}),"Ferma Animalelor");
}


//Constructori & Destructori
Game::Game():
prune("Assets/Textures/pruna.png",{0,40},"prune"),
player("Assets/Textures/player_fata.png", {940,540},"player",100,0,80.f,{ },{ })
{
    this->window = nullptr;
    this->initWindow();
    this->initAnimals();
    this->initCrops();
    this->initBuildings();
    this->initFonts();
    this->initUI();

}

void Game::initFonts() {
}

void Game::initUI() {
}

void Game::initAnimals() {
}

void Game::initBuildings() {
}

void Game::initCrops() {
}

void Game::updateInput(float dt) {
    player.movePlayer(dt);
}

void Game::updateInteractions() {
}

void Game::updatePlants(float dt) {
}

void Game::updateMessage(float dt) {
}

void Game::renderUI() {
}

void Game::renderAnimals() {
}

void Game::renderBuildings() {
}

void Game::renderCrops() {
}

Game::~Game() {
    delete this->window;
}

//Getters & Setters
bool Game::isRunning() const {
    return this->window->isOpen();
}

//Metode Publice
void Game::update() {
    float dt = dtClock.restart().asSeconds();
    while (const std::optional optEvent = window->pollEvent())
    {
        if (optEvent->is<sf::Event::Closed>())
        {
            window->close();
        }
        if (const auto* keyPressed = optEvent->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window->close();

        }
    }

    updateInput(dt);

}
void Game::render() {
    this->window->clear(sf::Color::Black);
    sf::Font font("Assets/Monocraft.ttf");
    sf::Text text(font);
    std::ostringstream oss;
    oss << "Stats|Guts:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.get_stats().get_guts())
        << "|Intelligence:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.get_stats().get_intelligence())
        << "|Charm:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.get_stats().get_charm());
    text.setString(oss.str());
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    window->draw(text);
    sf::Texture texture1("Assets/cristi_fata.png", false, sf::IntRect({10, 10}, {100, 100}));
    sf::Sprite sprite1(texture1);
    sprite1.setPosition({100.f, 100.f}); // absolute position
    window->draw(sprite1);
    player.draw(*window);
    prune.draw(*window);
    this->window->display();
}