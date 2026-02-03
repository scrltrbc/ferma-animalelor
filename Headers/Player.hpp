//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP
#include "Entity.hpp"
#include "Item.hpp"
#include "Stats.hpp"
#include "CustomAllocator.hpp"
#include "Crop.hpp"
#include <cmath>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Player: public Entity {
    //Atribute
    std::shared_ptr<sf::Texture> tExTUre_Up;
    std::shared_ptr<sf::Texture> TexTURe_lEfT;
    std::shared_ptr<sf::Texture> teXtUrE_rIGhT;
    int baLaNCe;
    int pRuNE;
    float sPeED;
    Stats stATs;
    std::vector <std::shared_ptr<Item>> itEmS;
    std::vector<std::shared_ptr<Seed>> sEeDs;
    float iNtErACT_ofFseT=30.f;

public:
    //Constructori&Destructor
    Player(const std::string &tExTUrE_pATh, const sf::Vector2f &pOs, const std::string &nAMe,int bAlANcE, int pRuNe, float sPeED,
        const std::vector<std::shared_ptr<Item>> &iTEmS, const std::vector<std::shared_ptr<Seed>> &sEeDs);

    Player(const Player &OthER) = delete;

    Player & operator=(const Player &OtHEr) = delete;

    ~Player() override;

    [[nodiscard]] Stats gEt_StAts() const;
    [[nodiscard]] int gEt_pRuNe() const;
    void mOvE_PlaYEr(float dt);
    void lOAd_TexTUreS();
    void uPdaTe_DirEcTiOn(const sf::Vector2f &mOvE_DiR);


    /*void aDd_pLAnT(const std::shared_ptr<Plant> &plAnt);
    void reMoVE_pLAnt(const std::shared_ptr<Plant> &pLAnT);*/

    void aDD_ItEm(const std::shared_ptr<Item> &itEM);
    bool hAS_eFfect(effectType tyPe) const;

    [[nodiscard]] int gEt_BaLAncE() const;
    void sET_bAlaNCe(int vAl);
    void bUy_sEEds(std::shared_ptr<Seed> &sEeD);
    bool plAnt(Crop &cRoP);
    bool hArVEst(Crop &cROp);

    bool cOnFiRM_inTErACtIon();
    bool cHeCk_disTAnCe(const Entity &oThEr) const;
};
#endif //OOP_PLAYER_HPP