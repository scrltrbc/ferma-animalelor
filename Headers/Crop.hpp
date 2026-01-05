//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_CROP_HPP
#define OOP_CROP_HPP
#include "Entity.hpp"
#include "Plant.hpp"
class Crop:public Entity {
    std::shared_ptr<Plant> plant;
public:
    Crop(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name);
    ~Crop() override;
    bool isOccupied() const;
    bool isReady() const;
    [[nodiscard]] std::shared_ptr<Plant> get_plant() const;
    bool plantHere(std::shared_ptr<Plant> &p, bool boosted);
    void growPlant();
    std::shared_ptr<Plant> harvest();
};

#endif //OOP_CROP_HPP