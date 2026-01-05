//
// Created by becbu on 12/7/2025.
//

#include "../Headers/Crop.hpp"

Crop::Crop(const std::string &texturePath, const sf::Vector2f &pos, const std::string &name):
        Entity(texturePath, pos, name),plant(nullptr){}

Crop::~Crop()=default;

bool Crop::isOccupied() const {
        return plant!=nullptr;
}

bool Crop::isReady() const {
        return isOccupied()&&plant->isReady();
}

std::shared_ptr<Plant> Crop::get_plant() const {
        return plant;
}

bool Crop::plantHere(std::shared_ptr<Plant> &p, bool boosted) {
        if (plant!=nullptr)
                return false;
        plant=p;
        plant->plantAt(getPosition(), boosted);
        return true;
}

void Crop::growPlant() {
        if (isOccupied())
                plant->grow();
}

std::shared_ptr<Plant> Crop::harvest() {
        if (!plant || !plant->isReady())
                return nullptr;

        auto harvested = plant;
        plant.reset();
        return harvested;
}
