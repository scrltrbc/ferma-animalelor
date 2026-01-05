//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Cafe.hpp"

Cafe::Cafe(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name):Building(texturePath,pos,name){
}

void Cafe::visit(Player &player) {
    int val ;
    if (player.hasEffect(effectType::increaseCharm))
        val = 7 + (std::rand() % 5);
    else
        val = 2 + std::rand() % 5;
    player.get_stats().set_charm(val);
    Day::instance().changeDayPhase();
}
