
#ifndef OOP_ENTITY_HPP
#define OOP_ENTITY_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
    //Atribute
protected:
    std::shared_ptr<sf::Texture> tExTUre;
    sf::Sprite sPrItE;
    const std::string nAMe;
public:

    //Constructori&Destructori
    Entity(const std::string &teXtURe_PaTH, const sf::Vector2f &pOs, const std::string &nAmE);

    virtual ~Entity() = 0;

    Entity(const Entity &oThER);
    Entity(Entity &&oThER) noexcept;

    //Getters&Setters
    [[nodiscard]] const std::string& gET_nAmE() const;
     sf::Sprite& gEt_sPRiTe();
    [[nodiscard]] std::shared_ptr<sf::Texture> gEt_tExTuRe() const;
    virtual void dRaW(sf::RenderWindow &window) const;
    [[nodiscard]] virtual sf::Vector2f gET_PoSitIoN() const;
    virtual void seT_pOsITioN(const sf::Vector2f& pos);
    [[nodiscard]] virtual sf::FloatRect geT_gLoBAl_bOuNDs() const;
};

#endif //OOP_ENTITY_HPP