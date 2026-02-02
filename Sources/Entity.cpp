//
// Created by becbu on 12/6/2025.
//

#include "../Headers/Entity.hpp"
#include "../Headers/ResourceManager.hpp"

Entity::Entity(const std::string &teXtURe_PaTH, const sf::Vector2f &pOs, const std::string &nAmE)
    : tExTUre(ResourceManager<sf::Texture>().get(teXtURe_PaTH)), sPrItE(*tExTUre),nAMe(nAmE) {
    sPrItE.setPosition(pOs);
}
Entity::~Entity()=default;

Entity::Entity(const Entity &other)
        : tExTUre(other.tExTUre),
          sPrItE(other.sPrItE),
          nAMe(other.nAMe) {
}

Entity::Entity(Entity &&other) noexcept
    : tExTUre(std::move(other.tExTUre)),
      sPrItE(std::move(other.sPrItE)),
      nAMe(other.nAMe) {
}


//Getters&Setters
const std::string& Entity::gET_nAmE() const {
    return nAMe;
}

sf::Sprite& Entity::gEt_sPRiTe(){
    return sPrItE;
}

std::shared_ptr<sf::Texture> Entity::gEt_tExTuRe() const {
    return tExTUre;
}

void Entity::dRaW(sf::RenderWindow &window) const {
    window.draw(sPrItE);
}

sf::Vector2f Entity::gET_PoSitIoN() const {
    return sPrItE.getPosition();
}

void Entity::seT_pOsITioN(const sf::Vector2f &pos) {
    sPrItE.setPosition(pos);
}

sf::FloatRect Entity::geT_gLoBAl_bOuNDs() const {
    return sPrItE.getGlobalBounds();
}
