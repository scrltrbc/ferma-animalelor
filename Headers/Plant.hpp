//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_PLANT_HPP
#define OOP_PLANT_HPP
#include "Entity.hpp"
#endif //OOP_PLANT_HPP

class Plant: public Entity {
    int seedCost;
    int sellingPrice;
    int growth;
    int growthCap;
    bool planted;
    bool boosted;
public:
    Plant(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name,int seedCost,int sellingPrice, int growthCap, bool planted,bool boosted);
    ~Plant() override;

    void plantAt(const sf::Vector2f &posCrop, bool applyboost);
    void grow();
    bool isReady() const;

    [[nodiscard]] int get_seed_cost() const;
    [[nodiscard]] int get_selling_price() const;
    [[nodiscard]] int get_growth() const;
    [[nodiscard]] int get_growth_cap() const;
    [[nodiscard]] bool is_planted() const;
    [[nodiscard]] bool is_boosted() const;
    void set_boosted(bool boosted);
};