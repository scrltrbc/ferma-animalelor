//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Cafe.hpp"

Cafe::Cafe(const std::string &tExTUrE_pAtH, const sf::Vector2f &pOs, const std::string &nAmE):Building(tExTUrE_pAtH,pOs,nAmE){
}

void Cafe::visit(Player &pLaYeR) {
    int vAl ;
    if (pLaYeR.hAS_eFfect(effectType::increaseCharm))
        vAl = 7 + (std::rand() % 5);
    else
        vAl = 2 + std::rand() % 5;
    pLaYeR.gEt_StAts().set_charm(vAl);
    Day::instance().cHaNgE_dAy_pHAsE();
}
