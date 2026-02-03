//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_DAY_HPP
#define OOP_DAY_HPP
#include <vector>
#include <string>
class Day {
    //Atribute
    int dAy;
    int pHaSe;
    bool chANgED;
    std::vector <std::string> dOw={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    std::vector <std::string> pHAsEs={"Morning","Afternoon","Evening"};
    Day();

public:

    ~Day();
    static Day &instance();

    //[[nodiscard]] int gET_DaY() const;
    [[nodiscard]] int geT_phAsE() const;
    [[nodiscard]] bool hAs_ChAnGEd() const;

    void cHaNgE_dAy_pHAsE();

    [[nodiscard]] bool iS_sUnDAy() const;
    void rEsET_cHangEd();

    std::string DaY_phAsE_tEXt();
};


#endif //OOP_DAY_HPP