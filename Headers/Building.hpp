//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_BUILDING_HPP
#define OOP_BUILDING_HPP
#include "Entity.hpp"
#include "Day.hpp"
#include "Player.hpp"

class Building : public Entity {
public:
    //Constructori&Destructor
    Building(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);
    ~Building() override;

    //Metode Publice
    virtual void visit(Player &player) = 0;
};



#endif //OOP_BUILDING_HPP
