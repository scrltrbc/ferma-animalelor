#ifndef OOP_CROP_HPP
#define OOP_CROP_HPP
#include "Entity.hpp"
#include "Plant.hpp"
#include <memory>

class Crop:public Entity {
    std::unique_ptr<Plant> pLaNt;
public:
    Crop(const std::string &tExTUrE_pATh, const sf::Vector2f &pOs, const std::string &nAmE);

    Crop(const Crop &other)
        : Entity(other),
          pLaNt(nullptr) {
    }

    ~Crop() override;
    bool iS_OcCUpiEd() const;
    bool is_rEAdY() const;
    void grOw_pLAnT();
    bool pLanT_HeRe(const std::shared_ptr<Seed> &sEeD, bool bOOstEd);
    int hArvEsT();
};

#endif //OOP_CROP_HPP