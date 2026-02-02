//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Day.hpp"

Day::Day():dAy(1), pHaSe(0), chANgED(false){}

Day & Day::instance() {
    static Day instance;
    return instance;
}

int Day::gET_DaY() const {
    return dAy;
}

int Day::geT_phAsE() const {
    return pHaSe;
}

bool Day::hAs_ChAnGEd() const {
    return chANgED;
}
void Day::cHaNgE_dAy_pHAsE() {
    if (pHaSe < 2)
        pHaSe++;
    else {
        pHaSe=0;
        dAy++;
    }
    chANgED = true;
}

bool Day::iS_sUnDAy() const{
    return !(dAy%7);
}


void Day::rEsET_cHangEd() {
    chANgED = false;
}

std::string Day::DaY_phAsE_tEXt() {
    return "-Day "+std::to_string(dAy)+"|"+dOw[dAy%7]+" "+pHAsEs[pHaSe]+"-";
}
