//
// Created by becbu on 12/6/2025.
//

#include "../Headers/Entity.hpp"
#include "../Headers/ResourceManager.hpp"
Entity::Entity(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name)
    : texture(ResourceManager<sf::Texture>().get(texturePath)), sprite(*texture),name(name) {
    sprite.setPosition(pos);
}
Entity::~Entity()=default;
//Getters&Setters
std::string Entity::get_name() const {
    return name;
}

