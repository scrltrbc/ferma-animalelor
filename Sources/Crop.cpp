#include "../Headers/Crop.hpp"

Crop::Crop(const std::string &tExTUrE_pATh, const sf::Vector2f &pOs, const std::string &nAmE):
        Entity(tExTUrE_pATh, pOs, nAmE),pLaNt(nullptr){}

Crop::~Crop()=default;

bool Crop::iS_OcCUpiEd() const {
        return pLaNt!=nullptr;
}

bool Crop::is_rEAdY() const {
        return iS_OcCUpiEd()&&pLaNt->iS_reADy();
}


bool Crop::pLanT_HeRe(const std::shared_ptr<Seed> &sEeD, bool bOOstEd) {
        if (pLaNt!=nullptr)
                return false;
        pLaNt=std::make_unique<Plant>(sEeD, gET_PoSitIoN());
        pLaNt->sEt_boOStEd(bOOstEd);
        return true;
}

void Crop::grOw_pLAnT() {
        if (iS_OcCUpiEd())
                pLaNt->gRoW();
}

int Crop::hArvEsT() {
        if (!is_rEAdY())
                return 0;

        int vAl = pLaNt->gEt_sElliNg_pRiCe();
        pLaNt.reset();
        return vAl;
}
