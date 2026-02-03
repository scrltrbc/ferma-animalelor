#include "../Headers/Game.hpp"
#include "../Headers/Stats.hpp"

//Metode Private
void Game::initWindow() {
    this->window= new sf::RenderWindow(sf::VideoMode({1920u,1080u}),"Ferma Animalelor");
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
    for (const auto &a: animals)
        entities.push_back(a);
    for (const auto &b: buildings)
        entities.push_back(b);
    for (const auto &c: crops)
        entities.push_back(c);
}

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

Game * Game::getInstance() {
    if (instance==nullptr)
        instance=new Game();
    return instance;
}

void Game::updateInput(float dt) {
    player.mOvE_PlaYEr(dt);
}


bool Game::updateInteractions() {
    if (!player.cOnFiRM_inTErACtIon())
        return false;
    for (auto const& e : entities) {
        if (player.cHeCk_disTAnCe(*e))
            continue;
        if (auto *animal=dynamic_cast<Animal*>(e.get())) {
            //animal->sAy_StUFf();
            animal->gIvE_RaNDom_iTeM();
            break;
        }
        if (auto *crop=dynamic_cast<Crop*>(e.get())) {
            if (player.plAnt(*crop))
                player.hArVEst(*crop);
            break;
        }
        if (auto* building = dynamic_cast<Building*>(e.get())) {
            if (auto *dojo=dynamic_cast<Dojo*>(building))
                dojo->visit(player);
            else if (auto *cafe=dynamic_cast<Cafe*>(building))
                cafe->visit(player);
            else if (auto *library=dynamic_cast<Library*>(building))
                library->visit(player);
            break;
        }
    }
    return true;
}


void Game::updateDay() {
    if (Day::instance().hAs_ChAnGEd()) {
        for (const auto& c : crops)
            c->grOw_pLAnT();
        if (Day::instance().iS_sUnDAy())
            prune.set_buying_price();
        else
            prune.set_selling_price();
        Day::instance().rEsET_cHangEd();
    }
}
/*
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
    for (auto const& c : crops) c->dRaW(*window);
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
    updateDay();
    updateInteractions();
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
    sf::Text text1(font);
    text1.setString(Day::instance().DaY_phAsE_tEXt());
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold);
    text1.setPosition({10, 1050});
    window->draw(text1);
    player.dRaW(*window);
    prune.dRaW(*window);
    renderBuildings();
    renderAnimals();
    renderCrops();
    this->window->display();
}
void Game::afis() {
    std::cout<<prune.get_price();
    player.aDD_ItEm(animals.begin()->get()->gIvE_RaNDom_iTeM());
}