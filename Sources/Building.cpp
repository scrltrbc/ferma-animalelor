//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Building.hpp"

Building::Building(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name):
        Entity(texturePath, pos, name){}

Building::~Building()=default;
