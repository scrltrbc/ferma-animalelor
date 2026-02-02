//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_CAFE_HPP
#define OOP_CAFE_HPP
#include "Building.hpp"

class Cafe : public Building {
public:
    Cafe(const std::string &tExTUrE_pAtH, const sf::Vector2f &pOs, const std::string &nAmE);
    void visit(Player &pLaYeR) override;
};
#endif //OOP_CAFE_HPP