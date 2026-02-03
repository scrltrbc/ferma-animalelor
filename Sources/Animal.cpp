//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Animal.hpp"
#include "../Headers/ResourceManager.hpp"
#include <cstdlib>

Animal::Animal(const std::string &teXtUre_PAth,
               const sf::Vector2f &pOS, const std::string &nAmE,
               const std::string &cAtchPhRAsE, const std::shared_ptr<Item> &iTEm):
               Entity(teXtUre_PAth, pOS, nAmE),
               cAtchPhRAsE(cAtchPhRAsE),
               iTem(iTEm) {
}

Animal::~Animal()=default;

/*void Animal::sAy_StUFf() {

}*/

std::shared_ptr<Item> Animal::gIvE_RaNDom_iTeM() {
    return iTem;
}