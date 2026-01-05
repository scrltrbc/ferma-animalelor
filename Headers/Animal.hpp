//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_ANIMAL_HPP
#define OOP_ANIMAL_HPP
#include "Entity.hpp"
#include "Item.hpp"
#include <memory>

class Animal : public Entity {
    std::shared_ptr<Item> item;
public:
    Animal(const std::string& texturePath,
           const sf::Vector2f& pos,
           const std::string& name,
           const std::shared_ptr<Item>& item);
    ~Animal() override;

    std::shared_ptr<Item> giveRandomItem();
};
#endif //OOP_ANIMAL_HPP