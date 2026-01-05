//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Item.hpp"

//Constructori&Destructori
Item::Item(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name, effectType effect)
        : Entity(texturePath, pos, name),
          effect(effect) {
}
Item::~Item()=default;

effectType Item::get_effect() const {
    return effect;
}
