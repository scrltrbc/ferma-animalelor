//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_ANIMAL_HPP
#define OOP_ANIMAL_HPP
#include "Entity.hpp"
#include "Item.hpp"
#include <memory>

class Animal : public Entity {
    std::string cAtchPhRAsE;
    std::shared_ptr<Item> iTem;
    //std::shared_ptr<Dialogue> dIaLoGUe;
public:
    Animal(const std::string& teXtUre_PAth,
           const sf::Vector2f& pOS,
           const std::string& nAmE,
           const std::string &cAtchPhRAsE,
           const std::shared_ptr<Item>& iTEm);
    ~Animal() override;

    void sAy_StUFf();
    std::shared_ptr<Item> gIvE_RaNDom_iTeM();


};
#endif //OOP_ANIMAL_HPP