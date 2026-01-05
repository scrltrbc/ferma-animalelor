//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP

#include<SFML/Graphics.hpp>
#include "Prune.hpp"
#include "Player.hpp"
#include "Animal.hpp"
#include "Building.hpp"
#include "Crop.hpp"
#include "ResourceManager.hpp"



class Game {
    //Atribute
    sf::Clock dtClock;
    sf::RenderWindow* window;
    ResourceManager<sf::Texture> textures;
    ResourceManager<sf::Font> fonts;
    Prune prune;
    Player player;
    std::vector<Animal> animals;
    std::vector<std::unique_ptr<Building>> buildings;
    std::vector<Crop> crops;
    //Metode Private
    void initWindow();
    void initFonts();
    void initUI();
    void initAnimals();
    void initBuildings();
    void initCrops();

    void updateInput(float dt);
    void updateInteractions();
    void updatePlants(float dt);
    void updateMessage(float dt);

    void renderUI();
    void renderAnimals();
    void renderBuildings();
    void renderCrops();

public:

    //Constructori&Destructor
    Game();
    ~Game();

    //Getters&Setters
    [[nodiscard]] bool isRunning() const;

    //Metode Publice
    void update();
    void render();

};
#endif //OOP_GAME_HPP