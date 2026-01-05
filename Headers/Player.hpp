//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP
#include "Entity.hpp"
#include "Item.hpp"
#include "Stats.hpp"
#include "CustomAllocator.hpp"
#include "Crop.hpp"
#include <cmath>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Player: public Entity {
    //Atribute
    std::shared_ptr<sf::Texture> texture_up;
    std::shared_ptr<sf::Texture> texture_left;
    std::shared_ptr<sf::Texture> texture_right;
    int balance;
    int prune;
    float speed;
    Stats stats;
    std::vector <std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Plant>> plants;

public:
    //Constructori&Destructor
    Player(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name,int balance, int prune, float speed,
        const std::vector<std::shared_ptr<Item>> &items, const std::vector<std::shared_ptr<Plant>> &plants);


    ~Player() override;

    [[nodiscard]] Stats get_stats() const;
    [[nodiscard]] int get_prune() const;
    void movePlayer(float dt);
    void loadTextures();
    void updateDirectionTexture(const sf::Vector2f& moveDir);

    void addPlant(const std::shared_ptr<Plant>& plant);
    void removePlant(const std::shared_ptr<Plant>& plant);
    [[nodiscard]] std::vector<std::shared_ptr<Plant>>& getPlants();

    void addItem(const std::shared_ptr<Item>& it);
    bool hasEffect(effectType type);

    [[nodiscard]] int get_balance() const;
    void set_balance(int val);

    bool tryPlant(Crop& crop);
    bool tryHarvest(Crop& crop);
};
#endif //OOP_PLAYER_HPP