//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Dojo.hpp"

#include "../Headers/Item.hpp"

Dojo::Dojo(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name):Building(texturePath,pos,name) {
}

void Dojo::visit(Player &player) {
    int val;
    if (player.hAS_eFfect(effectType::increaseGuts))
        val = 7 + (std::rand() % 5);
    else
        val = 2 + std::rand() % 5;
    player.gEt_StAts().set_guts(val);
    Day::instance().cHaNgE_dAy_pHAsE();
}
