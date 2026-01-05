
#ifndef OOP_ENTITY_HPP
#define OOP_ENTITY_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
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
     sf::Sprite& get_sprite();
    [[nodiscard]] std::shared_ptr<sf::Texture> get_texture() const;
    virtual void update() { }
    virtual void draw(sf::RenderWindow &window) const;
    [[nodiscard]] virtual sf::Vector2f getPosition() const;
    virtual void setPosition(const sf::Vector2f& pos);
    [[nodiscard]] virtual sf::FloatRect getGlobalBounds() const;
};

#endif //OOP_ENTITY_HPP