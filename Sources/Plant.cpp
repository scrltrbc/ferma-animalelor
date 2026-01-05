//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Plant.hpp"

Plant::Plant(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name, int seedCost,
    int sellingPrice, int growthCap, bool planted, bool boosted) : Entity(texturePath, pos, name),seedCost(seedCost),
    sellingPrice(sellingPrice), growth(0), growthCap(growthCap), planted(planted), boosted(boosted){}

Plant::~Plant()=default;

void Plant::plantAt(const sf::Vector2f &posCrop, bool applyboost) {
    planted = true;
    growth = 1;
    setPosition(posCrop);
    if (applyboost)
        boosted = true;

}

void Plant::grow() {
    if (!planted) return;

    growth += boosted ? 2 : 1;

    if (growth > growthCap)
        growth = growthCap;
}

bool Plant::isReady() const {
    return planted&&(growth==growthCap);
}

int Plant::get_seed_cost() const {
    return seedCost;
}

int Plant::get_selling_price() const {
    return sellingPrice;
}

int Plant::get_growth() const {
    return growth;
}

int Plant::get_growth_cap() const {
    return growthCap;
}

bool Plant::is_planted() const {
    return planted;
}

bool Plant::is_boosted() const {
    return boosted;
}

void Plant::set_boosted(bool boosted) {
    this->boosted=boosted;
}
