
#include "../Headers/Seed.hpp"

Seed::Seed(const std::string &nAmE, const std::string &teXtUrE_paTh, int sEEd_cOsT, int sElliNg_pRicE,
           int gRoWth_CaP)
        : nAmE(nAmE),
          teXtUrE_paTh(teXtUrE_paTh),
          sEEd_cOsT(sEEd_cOsT),
          sElliNg_pRicE(sElliNg_pRicE),
          gRoWth_CaP(gRoWth_CaP) {
}

Seed::~Seed()=default;

[[nodiscard]] const std::string& Seed::get_nAMe() const {
    return nAmE;
}

const std::string& Seed::gEt_tEXtuRe_pATh() const {
    return teXtUrE_paTh;
}

int Seed::gEt_sEEd_cOsT() const {
    return sEEd_cOsT;
}

[[nodiscard]] int Seed::gET_sELliNG_pRIce() const {
    return sElliNg_pRicE;
}

[[nodiscard]] int Seed::gET_gROwTh_cAp() const {
    return gRoWth_CaP;
}