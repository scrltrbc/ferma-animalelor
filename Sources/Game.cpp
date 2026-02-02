#include "../Headers/Game.hpp"
#include "../Headers/Stats.hpp"


//Metode Private
void Game::initWindow() {
    this->window= new sf::RenderWindow(sf::VideoMode({1920u,1080u}),"Ferma Animalelor");
}


//Constructori & Destructori
Game::Game():
prune("Assets/Textures/pruna.png",{0,40},"prune"),
player("Assets/Textures/player_fata.png", {940,540},"player",100,0,80.f,{ },{ })
{
    this->window = nullptr;
    this->initWindow();
    this->initAnimals();
    this->initCrops();
    this->initBuildings();
    //this->initFonts();
    //this->initUI();

}

/*void Game::initFonts() {
}

void Game::initUI() {
}*/

void Game::initAnimals() {
    animals.push_back(std::make_shared<Animal>("Assets/Textures/cristi_fata.png",sf::Vector2f{100,100}, "Cristi", "miau",
        std::make_shared<Item>("Assets/Textures/cristi_fata.png", sf::Vector2f{2,3}, "ochelari", effectType::increaseIntelligence)));
    animals.push_back(std::make_shared<Animal>("Assets/Textures/doug.png",sf::Vector2f{50,900}, "Doug", "ham",
        std::make_shared<Item>("Assets/Textures/doug.png", sf::Vector2f{2,3}, "fertilizator", effectType::plantsGrowthBoost)));
}


void Game::initBuildings() {
    buildings.push_back(std::make_shared<Dojo>("Assets/Textures/Dojo.png", sf::Vector2f{1300,300}, "dojo"));
    buildings.push_back(std::make_shared<Cafe>("Assets/Textures/Cafe.png", sf::Vector2f{200,250}, "cafe"));
    buildings.push_back(std::make_shared<Library>("Assets/Textures/Library.png", sf::Vector2f{700,570}, "library"));
}

void Game::initCrops() {
    crops.push_back(std::make_shared<Crop>("Assets/Textures/crop.png", sf::Vector2f{1000,100}, "crop"));
    crops.push_back(std::make_shared<Crop>("Assets/Textures/crop.png", sf::Vector2f{1100,100}, "crop"));
}

void Game::initEntities() {
    for (auto &a: animals)
        entities.push_back(a);
    for (auto &b: buildings)
        entities.push_back(b);
    for (auto &c: crops)
        entities.push_back(c);
}

void Game::updateInput(float dt) {
    player.mOvE_PlaYEr(dt);
}

/*
void Game::updateInteractions() {
}

void Game::updatePlants(float dt) {
}

void Game::updateMessage(float dt) {
}

void Game::renderUI() {
}
*/

void Game::renderAnimals() {
    for (auto &a : animals) a->dRaW(*window);
}

void Game::renderBuildings() {
    for (auto &b : buildings) b->dRaW(*window);
}

void Game::renderCrops() {
    for (auto &c : crops) c->dRaW(*window);
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
    float dt = dtClock.restart().asSeconds();
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

    updateInput(dt);

}
void Game::render() {
    this->window->clear(sf::Color::Black);
    sf::Font font("Assets/Monocraft.ttf");
    sf::Text text(font);
    std::ostringstream oss;
    oss << "Stats|Guts:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.gEt_StAts().get_guts())
        << "|Intelligence:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.gEt_StAts().get_intelligence())
        << "|Charm:" << std::setw(3) << std::setfill(' ')
        << std::to_string(player.gEt_StAts().get_charm());
    text.setString(oss.str());
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    window->draw(text);
    player.dRaW(*window);
    prune.dRaW(*window);
    renderBuildings();
    renderAnimals();
    renderCrops();
    this->window->display();
}