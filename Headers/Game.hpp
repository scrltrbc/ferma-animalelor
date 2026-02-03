
#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP

#include<SFML/Graphics.hpp>
#include "Prune.hpp"
#include "Player.hpp"
#include "Animal.hpp"
#include "Building.hpp"
#include "Crop.hpp"
#include "ResourceManager.hpp"
#include "Dojo.hpp"
#include "Day.hpp"
#include "Cafe.hpp"
#include "Library.hpp"
#include "Exceptions.hpp"



class Game {
    //Atribute
    static Game* instance;
    sf::Clock dtClock;
    sf::RenderWindow* window;
    ResourceManager<sf::Texture> textures;
    ResourceManager<sf::Font> fonts;
    Prune prune;
    Player player;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Animal>> animals;
    std::vector<std::shared_ptr<Building>> buildings;
    std::vector<std::shared_ptr<Crop>> crops;
    //Metode Private
    void initWindow();
    //void initFonts();
    //void initUI();
    void initAnimals();
    void initBuildings();
    void initCrops();
    void initEntities();
    Game();
    void updateInput(float dt);
    bool updateInteractions();
    void updateDay();
    //void updateMessage(float dt);

    //void renderUI();
    void renderAnimals();
    void renderBuildings();
    void renderCrops();

public:

    //Constructori&Destructor
    ~Game();
    Game(const Game&)=delete;
    Game& operator=(const Game&)=delete;
    static Game* getInstance();
    //Getters&Setters
    [[nodiscard]] bool isRunning() const;

    //Metode Publice
    void update();
    void render();
    void afis();

};
#endif //OOP_GAME_HPP