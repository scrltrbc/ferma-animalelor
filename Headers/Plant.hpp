
#ifndef OOP_PLANT_HPP
#define OOP_PLANT_HPP
#include "Entity.hpp"
#include "Seed.hpp"

class Plant: public Entity {
    std::shared_ptr<const Seed> sEeD;
    int gRoWTh=0;
    bool bOOstED=false;
public:
    Plant(const std::shared_ptr<const Seed>& seED, const sf::Vector2f &pOs);
    ~Plant() override;

    void gRoW();
    bool iS_reADy() const;

    [[nodiscard]] int gEt_sElliNg_pRiCe() const;
    [[nodiscard]] bool is_bOOstEd() const;
    void sEt_boOStEd(bool bOOsTEd);
};
#endif //OOP_PLANT_HPP