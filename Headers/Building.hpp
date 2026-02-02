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
    Building(const std::string &teXtURe_pATh, const sf::Vector2f &pOS, const std::string &nAmE);
    ~Building() override;

    //Metode Publice
    virtual void visit(Player &pLaYeR) = 0;
};



#endif //OOP_BUILDING_HPP
