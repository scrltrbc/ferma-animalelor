//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Library.hpp"

Library::Library(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name):Building(texturePath,pos,name) {
}

void Library::visit(Player &player) {
    int val;
    if (player.hasEffect(effectType::increaseIntelligence))
        val = 7 + (std::rand() % 5);
    else
        val = 2 + std::rand() % 5;
    player.get_stats().set_intelligence(val);
    Day::instance().changeDayPhase();
}
