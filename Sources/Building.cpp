//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Building.hpp"

Building::Building(const std::string &teXtURe_pATh, const sf::Vector2f &pos, const std::string &nAmE):
        Entity(teXtURe_pATh, pos, nAmE){}

Building::~Building()=default;
