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

sf::Sprite& Entity::get_sprite(){
    return sprite;
}

std::shared_ptr<sf::Texture> Entity::get_texture() const {
    return texture;
}

void Entity::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

void Entity::setPosition(const sf::Vector2f &pos) {
    sprite.setPosition(pos);
}

sf::FloatRect Entity::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}
