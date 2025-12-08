//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP

#include<SFML/Graphics.hpp>

class Game {
    //Atribute
    sf::RenderWindow* window;
    //Metode Private
    void initWindow();

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