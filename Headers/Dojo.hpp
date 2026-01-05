//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_DOJO_HPP
#define OOP_DOJO_HPP
#include "Building.hpp"

class Dojo : public Building {
public:
    Dojo(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);
    void visit(Player &player) override;
};
#endif //OOP_DOJO_HPP