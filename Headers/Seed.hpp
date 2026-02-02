
#ifndef OOP_SEED_HPP
#define OOP_SEED_HPP
#include <string>
class Seed {
    const std::string nAmE;
    std::string teXtUrE_paTh;
    int sEEd_cOsT;
    int sElliNg_pRicE;
    int gRoWth_CaP;
public:
    Seed(const std::string &nAmE, const std::string &teXtUrE_paTh, int sEEd_cOsT, int sElliNg_pRicE, int gRoWth_CaP);
    ~Seed();

    [[nodiscard]] const std::string& get_nAMe() const;
    [[nodiscard]] const std::string& gEt_tEXtuRe_pATh() const;
    [[nodiscard]] int gEt_sEEd_cOsT() const;
    [[nodiscard]] int gET_sELliNG_pRIce() const;
    [[nodiscard]] int gET_gROwTh_cAp() const;
};

#endif //OOP_SEED_HPP