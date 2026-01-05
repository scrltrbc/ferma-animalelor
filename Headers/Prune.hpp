//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_PRUNE_HPP
#define OOP_PRUNE_HPP
#include "Entity.hpp"

class Prune: public Entity {
    //Atribute
    int price;
public:
    //Constructori&Destructor
    Prune(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);
    ~Prune() override;

    //Getters&Setters
    [[nodiscard]] int get_price() const;

    void set_buying_price();
    void set_selling_price();

};



#endif //OOP_PRUNE_HPP