//
// Created by becbu on 12/6/2025.
//

#ifndef OOP_ENTITY_HPP
#define OOP_ENTITY_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Entity {
    //Atribute
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    const std::string name;
public:

    //Constructori&Destructori
    Entity(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);

    virtual ~Entity() = 0;

    //Getters&Setters
    [[nodiscard]] std::string get_name() const;

    virtual void update() { }
    virtual void draw(sf::RenderWindow &window) const = 0;
    [[nodiscard]] virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition(const sf::Vector2f& pos) = 0;
    [[nodiscard]] virtual sf::FloatRect getGlobalBounds() const = 0;
};

#endif //OOP_ENTITY_HPP