//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Animal.hpp"
#include "../Headers/ResourceManager.hpp"
#include <cstdlib>

Animal::Animal(const std::string& texturePath,
               const sf::Vector2f& pos,
               const std::string& name,
               const std::shared_ptr<Item>& item)
    : Entity(texturePath, pos, name),item(item){}
Animal::~Animal()=default;

std::shared_ptr<Item> Animal::giveRandomItem() {
    return item;
}