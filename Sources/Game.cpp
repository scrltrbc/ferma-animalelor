//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Game.hpp"
#include "../Headers/Stats.hpp"
//Metode Private
void Game::initWindow() {
    this->window= new sf::RenderWindow(sf::VideoMode({1920u,1080u}),"Ferma Animalelor");
}


//Constructori & Destructori
Game::Game() {
    this->window = nullptr;
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

//Getters & Setters
bool Game::isRunning() const {
    return this->window->isOpen();
}

//Metode Publice
void Game::update() {

    while (const std::optional optEvent = window->pollEvent())
    {
        if (optEvent->is<sf::Event::Closed>())
        {
            window->close();
        }
        if (const auto* keyPressed = optEvent->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window->close();
        }
    }
}
void Game::render() {
    Stats stats;
    this->window->clear(sf::Color::Black);
    sf::Font font("Assets/Monocraft.ttf");
    sf::Text text(font);
    std::ostringstream oss;
    oss << "Stats|Guts:" << std::setw(3) << std::setfill(' ')
        << std::to_string(stats.Stats::get_guts())
        << "|Intelligence:" << std::setw(3) << std::setfill(' ')
        << std::to_string(stats.Stats::get_intelligence())
        << "|Charm:" << std::setw(3) << std::setfill(' ')
        << std::to_string(stats.Stats::get_charm());
    text.setString(oss.str());
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    window->draw(text);

    sf::Texture texture1("Assets/cristi_fata.png", false, sf::IntRect({10, 10}, {100, 100}));
    sf::Sprite sprite1(texture1);
    sprite1.setPosition({100.f, 100.f}); // absolute position
    sf::Texture texture2("Assets/player_fata.png", false, sf::IntRect({10, 10}, {100, 100}));
    sf::Sprite sprite2(texture2);
    sprite2.setPosition({200.f, 100.f});
    window->draw(sprite1);
    window->draw(sprite2);
    this->window->display();
}