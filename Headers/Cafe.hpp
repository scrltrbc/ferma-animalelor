//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_CAFE_HPP
#define OOP_CAFE_HPP
#include "Building.hpp"

class Cafe : public Building {
public:
    Cafe(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);
    void visit(Player &player) override;
};
#endif //OOP_CAFE_HPP