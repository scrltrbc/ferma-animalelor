//
// Created by becbu on 12/7/2025.
//

#include "../Headers/Prune.hpp"

Prune::Prune(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name): Entity(texturePath, pos, name),price(0) {
    set_selling_price();
}

Prune::~Prune()=default;

int Prune::get_price() const {
    return price;
}

void Prune::set_buying_price() {
    price = 11 + rand()%(1022);
}

void Prune::set_selling_price() {
    price = 5 + rand()%(INT_MAX-4);
}

