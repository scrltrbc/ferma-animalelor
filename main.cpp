/*/*
#include <iostream>
#include <string>
#include <chrono>
#include <utility>
#include <climits>
#include <vector>
#include <algorithm>
#include <random>

class Stats {
    int guts;
    int intelligence;
    int charm;
public:
    Stats() : guts(0), intelligence(0), charm(0) {}
    ~Stats() = default;

    [[nodiscard]] int get_guts() const { return guts; }
    [[nodiscard]] int get_intelligence() const { return intelligence; }
    [[nodiscard]] int get_charm() const { return charm; }

    void set_guts(int val) { guts = std::min(100, guts + val); }
    void set_intelligence(int val) { intelligence = std::min(100, intelligence + val); }
    void set_charm(int val) { charm = std::min(100, charm + val); }

    friend std::ostream& operator<<(std::ostream& os, const Stats& stats) {
        os << stats.guts << '\n' << stats.intelligence << '\n' << stats.charm << '\n';
        return os;
    }
};

enum class effectType {
    multiplyGuts,
    multiplyIntelligence,
    multiplyCharm,
    plantsGrowthBoost
};

class Item {
    std::string name;
    effectType effect;
public:
    Item(std::string name, effectType effect) : name(std::move(name)), effect(effect) {}
    ~Item() = default;

    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] effectType get_effect() const { return effect; }

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << item.get_name() << '\n';
        return os;
    }
};

class Prune {
    int buyingPrice;
    int sellingPrice;
public:
    Prune() {
        buyingPrice = rand();
        sellingPrice = 0;
    }
    ~Prune() = default;

    [[nodiscard]] int get_buying_price() const { return buyingPrice; }
    [[nodiscard]] int get_selling_price() const { return sellingPrice; }

    void set_buying_price() { buyingPrice = rand(); }
    void set_selling_price() { sellingPrice = rand(); }

    friend std::ostream& operator<<(std::ostream& os, const Prune& prune) {
        os << prune.buyingPrice << '\n' << prune.sellingPrice << '\n';
        return os;
    }
};

class Seed {
    std::string name;
    int seedCost;
public:
    Seed(std::string name, int seed_cost) : name(std::move(name)), seedCost(seed_cost) {}
    ~Seed() = default;

    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] int get_seed_cost() const { return seedCost; }

    friend std::ostream& operator<<(std::ostream& os, const Seed& seed) {
        os << seed.name << '\n' << seed.seedCost;
        return os;
    }
};

class Plant : public Seed {
    int turnsSincePlanted;
    int sellingPrice;
public:
    Plant(const std::string& name, int seed_cost, int selling_price)
        : Seed(name, seed_cost), turnsSincePlanted(0), sellingPrice(selling_price) {}

    [[nodiscard]] int get_turns_since_planted() const { return turnsSincePlanted; }
    [[nodiscard]] int get_selling_price() const { return sellingPrice; }

    void set_turns_since_planted() { ++turnsSincePlanted; }
    void set_selling_price(int selling_price) { sellingPrice = selling_price; }

    friend std::ostream& operator<<(std::ostream& os, const Plant& plant) {
        os << plant.get_name() << '\n' << plant.sellingPrice << '\n' << plant.turnsSincePlanted << '\n';
        return os;
    }
};

class NPC {
    std::string name;
public:
    explicit NPC(std::string name) : name(std::move(name)) {}
    virtual ~NPC() = default;
    virtual void sayStuff() { std::cout << "Hello!\n"; }

    [[nodiscard]] const std::string& get_name() const { return name; }

    friend std::ostream& operator<<(std::ostream& os, const NPC& npc) {
        os << npc.name << '\n';
        return os;
    }
};

class Animal : public NPC {
    Item item;
    std::string catchphrase;
public:
    Animal(const std::string& name, const Item& item, std::string catchphrase)
        : NPC(name), item(item), catchphrase(std::move(catchphrase)) {}

    void sayStuff() override { std::cout << get_name() << ": " << catchphrase << '\n'; }

    static bool giveItem() { return rand() % 4 == 0; }

    [[nodiscard]] const Item& get_item() const { return item; }
    [[nodiscard]] const std::string& get_catchphrase() const { return catchphrase; }

    friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        os << animal.get_name() << '\n' << animal.get_catchphrase() << '\n' << animal.get_item() << '\n';
        return os;
    }
};

enum class Phase { Morning, Afternoon, Evening };

std::vector<std::string> days{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

class GameEngine {
    static GameEngine* instance;
    int crtDay;
    Phase phase;

    GameEngine(int crtDay, Phase phase) : crtDay(crtDay), phase(phase) {}
    void changeDays() {
        ++crtDay;
        phase = Phase::Morning;
    }

public:
    static GameEngine* getInstance() {
        if (instance == nullptr) {
            instance = new GameEngine(0, Phase::Morning);
        }
        return instance;
    }
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

    [[nodiscard]] int get_crt_day() const { return crtDay; }
    [[nodiscard]] Phase get_phase() const { return phase; }

    void set_phase(Phase newPhase) { phase = newPhase; }

    void changePhase() {
        if (phase == Phase::Morning)
            set_phase(Phase::Afternoon);
        else if (phase == Phase::Afternoon)
            set_phase(Phase::Evening);
        else
            changeDays();
    }
};
GameEngine* GameEngine::instance = nullptr;

class Player {
    const std::string name;
    Stats stats;
    int balance;
    int crop_slots;
    int prune;
    int crops_used;
    std::vector<Item> items;
    std::vector<std::string> seeds;
    std::vector<Plant> plantedPlants;

    bool hasEffect(effectType eff) const {
        return std::any_of(items.begin(), items.end(),
                           [eff](const Item& i) { return i.get_effect() == eff; });
    }

public:
    explicit Player(std::string name)
        : name(std::move(name)), balance(100), crop_slots(5), prune(0), crops_used(0) {}

    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] int get_balance() const { return balance; }
    void set_balance(int val) {
        if (balance > INT_MAX - val) balance = INT_MAX;
        else balance += val;
    }
    [[nodiscard]] int get_crop_slots() const { return crop_slots; }
    [[nodiscard]] int get_prune() const { return prune; }
    [[maybe_unused]] [[nodiscard]] const std::vector<Item>& get_items() const { return items; }
    [[maybe_unused]] [[nodiscard]] const std::vector<std::string>& get_seeds() const { return seeds; }

    void playSwordsWithMaster() {
        int base = 2 + (rand() % 6);
        int bonus = hasEffect(effectType::multiplyGuts) ? 2 : 0;
        stats.set_guts(base + bonus);
        GameEngine::getInstance()->changePhase();
    }
    void goToLibrary() {
        int base = 2 + (rand() % 6);
        int bonus = hasEffect(effectType::multiplyIntelligence) ? 2 : 0;
        stats.set_intelligence(base + bonus);
        GameEngine::getInstance()->changePhase();
    }
    void workAtTheCafe() {
        int base = 2 + (rand() % 6);
        int bonus = hasEffect(effectType::multiplyCharm) ? 2 : 0;
        stats.set_charm(base + bonus);
        GameEngine::getInstance()->changePhase();
    }

    bool buySeeds(const Seed& seed, int howmany) {
        if (howmany <= 0) {
            std::cout << "Didn't buy any!\n";
            return false;
        }
        auto cost = static_cast<long long>(howmany) * seed.get_seed_cost();
        if (cost > balance) {
            std::cout << "Not enough money :(\n";
            return false;
        }
        for (int i = 0; i < howmany; ++i) seeds.push_back(seed.get_name());
        balance -= static_cast<int>(cost);
        return true;
    }

    bool plantSeed(const Seed& seed) {
        if (crops_used >= crop_slots) return false;
        for (size_t i = 0; i < seeds.size(); ++i) {
            if (seeds[i] == seed.get_name()) {
                seeds.erase(seeds.begin() + static_cast<long>(i));
                plantedPlants.emplace_back(seed.get_name(), seed.get_seed_cost(), seed.get_seed_cost() * 2);
                ++crops_used;
                return true;
            }
        }
        return false;
    }

    int plantMultipleSeeds(const Seed& seed, int howmany) {
        if (howmany <= 0) return 0;
        int count = 0;
        for (int i = 0; i < howmany && plantSeed(seed); ++i) ++count;
        return count;
    }

    [[maybe_unused]] void growAllSeeds() {
        for (auto& pp : plantedPlants) pp.set_turns_since_planted();
    }

    int harvestAndSell() {
        int earnings = 0;
        auto p = plantedPlants.begin();
        while (p != plantedPlants.end()) {
            int needed = hasEffect(effectType::plantsGrowthBoost) ? 3 : 6;
            if (p->get_turns_since_planted() >= needed) {
                earnings += p->get_selling_price();
                p = plantedPlants.erase(p);
            } else ++p;
        }
        set_balance(earnings);
        return earnings;
    }

    bool buyCropSlot(int cost, int howmany) {
        if (howmany <= 0 || crop_slots > (100 - howmany) || cost * howmany > balance) return false;
        set_balance(-cost * howmany);
        crop_slots += howmany;
        return true;
    }

    bool buyPrune(int howmany, const Prune& p) {
        if (howmany <= 0 || p.get_selling_price() * howmany > balance) return false;
        balance -= p.get_selling_price() * howmany;
        prune += howmany;
        return true;
    }

    bool sellPrune(int howmany, const Prune& p) {
        if (howmany <= 0 || howmany > prune) {
            std::cout << "You don't have that many prune :(\n";
            return false;
        }
        set_balance(howmany * p.get_selling_price());
        prune -= howmany;
        return true;
    }

    void obtainItem(const Item& i) { items.push_back(i); }

    [[nodiscard]] bool checkVictory() const {
        return stats.get_intelligence() >= 100 || stats.get_guts() >= 100 ||
               stats.get_charm() >= 100 || get_balance() >= INT_MAX;
    }

    void display_stats(const Prune& pr) const {
        std::cout << get_name() << "'s stats:\n";
        std::cout << "Guts: " << stats.get_guts()
                  << " | Intelligence: " << stats.get_intelligence()
                  << " | Charm: " << stats.get_charm() << '\n';
        std::cout << "Balance: " << get_balance() << "\nPrune: " << get_prune()
                  << "\nPrune Buying Price (Sunday Only): " << pr.get_buying_price()
                  << "\nPrune Selling Price: " << pr.get_selling_price()
                  << "\nCrop Slots: " << get_crop_slots()
                  << "\nCrops Used: " << crops_used << '\n';
    }
};

class prune_vendor : public NPC {
public:
    explicit prune_vendor(const std::string& name) : NPC(name) {}
    void sayStuff() override {
        std::cout << get_name() << " the prune vendor: Good greetings, esteemed citizen! I hear you would you like to purchase some prune?\nThey come at a great price and can be sold at an even greater one,\n but I would advise you to still be wise when making any kind of investment...\n";
    }
};

bool isSunday(int day) { return day % 7 == 6; }

void print_title() { std::cout << "Welcome to Ferma Animalelor!\n"; }

void print_menu() {
    std::cout << "\nActions (choose number):\n"
              << "1. Read at library (gain intelligence)\n"
              << "2. Play swords with Farm Swordmaster (gain guts)\n"
              << "3. Work at cafe (earn charm & money)\n"
              << "4. Buy seeds\n"
              << "5. Plant seed from inventory\n"
              << "6. Buy crop slots (cost $100/slot)\n"
              << "7. Talk to someone (25% chance to get an item)\n"
              << "8. Buy prune (Sunday only)\n"
              << "9. Sell prune (Mon-Sat)\n"
              << "10. Exit\n";
}

int main() {
    srand(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    print_title();

    std::cout << "What's your name?\n";
    std::string name;
    std::cin >> name;

    Player player(name);
    std::cout << "Hello, " << player.get_name() << "!\nYour new start at Ferma Animalelor begins!\n";

    std::vector<Seed> seeds = {{"Turnip", 5}, {"Carrot", 8}, {"Wheat", 10}, {"Tomato", 12}};

    Item PinkBow("Pink Bow", effectType::multiplyCharm);
    Item Glasses("Glasses", effectType::multiplyIntelligence);
    Item PluckSword("Pluck Sword", effectType::multiplyGuts);
    Item GreenMonster("Green Monster", effectType::plantsGrowthBoost);

    std::vector<Animal> animals = {
        {"Bill the Duck", PluckSword, "What the duck!"},
        {"Miss Piggy(TM)", PinkBow, "Oink!"},
        {"Aizen", GreenMonster, "Yokoso watashi no ferma animalelor iye!"},
        {"Cristi", Glasses, "You are in a realm by yourself, the laughing stock of your village.\nYou are a comedic vessel that has no port or harbor,\na joke of a wanderer with no destination...\nMiau!\n"}
    };

    prune_vendor pruneSella("Adrian");
    Prune bursaprunelor;
    bursaprunelor.set_selling_price();
    bursaprunelor.set_buying_price();

    while (!player.checkVictory()) {
        int day = GameEngine::getInstance()->get_crt_day();
        Phase phase = GameEngine::getInstance()->get_phase();
        std::cout << "--- Day " << day << " " << days[day % 7] << " ";
        if (phase == Phase::Afternoon) std::cout << "Afternoon\n";
        else if (phase == Phase::Morning) std::cout << "Morning\n";
        else std::cout << "Evening\n";
        std::cout << " ---\n";

        player.display_stats(bursaprunelor);
        player.harvestAndSell();
        print_menu();

        int choice = 0;
        std::cout << "What do you want to do?\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                player.goToLibrary();
                std::cout<<"You went to the library and studied for quite a long time, you feel smarter now.\n";
                break;
            case 2:
                player.playSwordsWithMaster();
                std::cout<<"You clashed swords with the farm's masterswordsman, you feel tired, but a raging spirit is firing up within you now.\n";
                break;
            case 3:
                player.workAtTheCafe();
                std::cout<<"You just finished a shift at the local cafe, you got some money and feel more sociable now.\n";
                break;
            case 4: {
                int howmany, seedid;
                std::cout << "How many seeds and which kind [a number and 0-3]?\n";
                std::cin >> howmany >> seedid;
                player.buySeeds(seeds[seedid], howmany);
                break;
            }
            case 5: {
                int howmany, seedid;
                std::cout << "How many seeds and which kind [a number and 0-3]?\n";
                std::cin >> howmany >> seedid;
                if (howmany <= 1) player.plantSeed(seeds[seedid]);
                else player.plantMultipleSeeds(seeds[seedid], howmany);
                break;
            }
            case 6: {
                int howmany;
                std::cout << "How many crops would you like to buy?\n";
                std::cin >> howmany;
                player.buyCropSlot(100, howmany);
                break;
            }
            case 7: {
                int who;
                std::cout << "Who would you like to talk to? Enter a number 0-3:\n";
                std::cin >> who;
                animals[who].sayStuff();
                if (Animal::giveItem()) player.obtainItem(animals[who].get_item());
                break;
            }
            case 8:
                if (isSunday(day)) {
                    pruneSella.sayStuff();
                    int howmany;
                    std::cout << "How many prune?\n";
                    std::cin >> howmany;
                    player.buyPrune(howmany, bursaprunelor);
                } else std::cout << "You can only buy prune on Sunday!\n";
                break;
            case 9:
                if (!isSunday(day)) {
                    int howmany;
                    std::cout << "How many to sell?\n";
                    std::cin >> howmany;
                    player.sellPrune(howmany, bursaprunelor);
                } else std::cout << "You can only sell prune Monday–Saturday!\n";
                break;
            case 10:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
        GameEngine::getInstance()->changePhase();
    }
    std::cout << "Congratulations, you won!\n";
    return 0;
}
#1#
#include<iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({680, 400}), "Ferma");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}*/


#include "Headers/Player.hpp"
#include "Headers/CustomAllocator.hpp"
#include "Headers/Game.hpp"
int main() {
    Game game;
    while (game.isRunning()) {
        game.update();

        game.render();
    }
    return 0;
}
