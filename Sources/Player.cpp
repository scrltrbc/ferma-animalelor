#include "../Headers/Player.hpp"


Stats Player::gEt_StAts() const {
    return stATs;
}

int Player::gEt_pRuNe() const {
    return pRuNE;
}

Player::Player(const std::string &tExTUrE_pATh, const sf::Vector2f &pOs, const std::string &nAMe, int bAlANcE, int pRuNe, float sPeED,
               const std::vector<std::shared_ptr<Item>> &iTEmS, const std::vector<std::shared_ptr<Seed>> &sEeDs)
    : Entity(tExTUrE_pATh, pOs, nAMe),
          baLaNCe(bAlANcE),
          pRuNE(pRuNe),
          sPeED(sPeED),
          itEmS(iTEmS),
          sEeDs(sEeDs) { lOAd_TexTUreS();}

Player::~Player()=default;

void Player::mOvE_PlaYEr(float dt) {
    sf::Vector2f dir(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dir.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dir.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dir.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dir.x += 1;

    if (dir.x != 0 || dir.y != 0) {
        float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        dir /= len;

        uPdaTe_DirEcTiOn(dir);
        gEt_sPRiTe().move(dir * sPeED * dt);
    }
}

void Player::lOAd_TexTUreS() {
    TexTURe_lEfT=ResourceManager<sf::Texture>().get("C:/Users/becbu/CLionProjects/ferma-animalelor/cmake-build-debug/Assets/Textures/player_stanga.png");
    teXtUrE_rIGhT=ResourceManager<sf::Texture>().get("Assets/Textures/player_dreapta.png");
    tExTUre_Up=ResourceManager<sf::Texture>().get("Assets/Textures/player_spate.png");
}

void Player::uPdaTe_DirEcTiOn(const sf::Vector2f &dir) {
    if (dir.x == 0 && dir.y == 0)
        return;

    if (std::abs(dir.x) > std::abs(dir.y)) {
        if (dir.x > 0)
            gEt_sPRiTe().setTexture(*teXtUrE_rIGhT,true);
        else
            gEt_sPRiTe().setTexture(*TexTURe_lEfT,true);
    }
    else {
        if (dir.y > 0)
            gEt_sPRiTe().setTexture(*gEt_tExTuRe(),true);
        else
        gEt_sPRiTe().setTexture(*tExTUre_Up,true);
    }
}

/*void Player::aDd_pLAnT(const std::shared_ptr<Seed> &plAnt) {
    sEeDs.push_back(plAnt);
}*/

/*void Player::reMoVE_pLAnt(const std::shared_ptr<Plant> &pLAnT) {
    sEeDs.erase(std::remove(sEeDs.begin(), sEeDs.end(), pLAnT), sEeDs.end());
}*/

void Player::aDD_ItEm(const std::shared_ptr<Item> &itEM) {
    if (!hAS_eFfect(itEM->get_effect()))
        itEmS.push_back(itEM);
}

int Player::gEt_BaLAncE() const {
    return baLaNCe;
}

void Player::sET_bAlaNCe(int vAl) {
    if (baLaNCe<INT_MAX-vAl)
        baLaNCe += vAl;
    else
        baLaNCe=INT_MAX;
}

bool Player::plAnt(Crop &cRoP) {
    if (cRoP.iS_OcCUpiEd())
        return false;
    cRoP.pLanT_HeRe(sEeDs[0], hAS_eFfect(effectType::plantsGrowthBoost));
    sEeDs.erase(sEeDs.begin());
    return true;
}

bool Player::hArVEst(Crop &cROp) {
    if (!cROp.is_rEAdY())
        return false;

    sET_bAlaNCe(cROp.hArvEsT());
    return true;
}

bool Player::hAS_eFfect(effectType tyPe) const {
    for (const auto &i : itEmS)
        if (i->get_effect() == tyPe)
            return true;
    return false;
}

bool Player::cOnFiRM_inTErACtIon() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E);
}

bool Player::cHeCk_disTAnCe(const Entity &oThEr) const {
    sf::Vector2f d = oThEr.gET_PoSitIoN()-gET_PoSitIoN();
    return (d.x*d.x + d.y*d.y) <= (iNtErACT_ofFseT * iNtErACT_ofFseT);

}

void Player::bUy_sEEds(std::shared_ptr<Seed> &sEeD) {
    if (gEt_BaLAncE()>=sEeD->gEt_sEEd_cOsT()) {
        sET_bAlaNCe(-sEeD->gEt_sEEd_cOsT());
        sEeDs.push_back(sEeD);
    }

}