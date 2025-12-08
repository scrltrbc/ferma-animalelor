//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_ITEM_HPP
#define OOP_ITEM_HPP

#include "../Headers/Entity.hpp"
#include <string>

enum class effectType {
    increaseGuts,
    increaseIntelligence,
    increaseCharm,
    plantsGrowthBoost
};

class Item : public Entity{
    effectType effect;

public:
    //Constructori&Destructor
    Item(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name, effectType effect);

    [[nodiscard]] effectType get_effect() const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << item.get_name() << '\n';
        return os;
    }
};
#endif //OOP_ITEM_HPP