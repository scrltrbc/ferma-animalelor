#include <iostream>
#include <string>
#include <chrono>
#include <utility>
#include <climits>
#include <vector>
#include <algorithm>

class Stats {
    int guts;
    int intelligence;
    int charm;
public:
    Stats() : guts(0), intelligence(0), charm(0) {}

    [[nodiscard]] int get_guts() const {
        return guts;
    }

    ~Stats() = default;

    void set_guts(int val) {
        guts=std::min(100,guts+val);
    }

    [[nodiscard]] int get_intelligence() const {
        return intelligence;
    }

    void set_intelligence(int val) {
        intelligence=std::min(100,intelligence+val);
    }

    [[nodiscard]] int get_charm() const {
        return charm;
    }

    void set_charm(int val) {
        charm=std::min(100,charm+val);
    }
    friend std::ostream& operator<<(std::ostream &os, const Stats &stats) {
        os<<stats.guts<<std::endl;
        os<<stats.intelligence<<std::endl;
        os<<stats.charm<<std::endl;
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
    Item(std::string name, effectType effect):name(std::move(name)), effect(effect){}
    ~Item() = default;

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    [[nodiscard]] effectType get_effect() const {
        return effect;
    }
    friend std::ostream& operator<<(std::ostream &os, const Item &item) {
        os<<item.get_name()<<std::endl;
        return os;
    }
};

class Prune{
    int buyingPrice;
    int sellingPrice;
public:
    Prune()
    {
        buyingPrice=rand();
        sellingPrice=0;
    }

    ~Prune() = default;

    [[nodiscard]] int get_buying_price() const {
        return buyingPrice;
    }
    void set_buying_price() {
        buyingPrice=rand();
    }
    [[nodiscard]] int get_selling_price() const {
        return sellingPrice;
    }

    void set_selling_price() {
        sellingPrice=rand();
    }
    friend std::ostream& operator<<(std::ostream &os, const Prune &prune) {
        os<<prune.buyingPrice<<std::endl;
        os<<prune.sellingPrice<<std::endl;
        return os;
    }
};

class Seed {
    std::string name;
    int seedCost;

public:
    Seed(std::string name, int seed_cost)
        : name(std::move(name)),
          seedCost(seed_cost){
    }

    ~Seed() = default;

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    [[nodiscard]] int get_seed_cost() const {
        return seedCost;
    }
    friend std::ostream& operator<<(std::ostream &os, const Seed &seed) {
        os<<seed.name<<std::endl;
        os<<seed.seedCost;
        return os;
    }
};

class Plant : public Seed{
    int turnsSincePlanted;
    int sellingPrice;
public:
    Plant(const std::string &name, int seed_cost, int selling_price)
        : Seed(std::move(name), seed_cost),
          sellingPrice(selling_price),
          turnsSincePlanted(0) {
    }

    [[nodiscard]] int get_turns_since_planted() const {
        return turnsSincePlanted;
    }
    void set_turns_since_planted() {
        turnsSincePlanted++;
    }

    [[nodiscard]] int get_selling_price() const {
        return sellingPrice;
    }

    void set_selling_price(int selling_price) {
        sellingPrice = selling_price;
    }
    friend std::ostream& operator<<(std::ostream &os, const Plant &plant) {
        os<<plant.get_name()<<std::endl;
        os<<plant.sellingPrice<<std::endl;
        os<<plant.turnsSincePlanted<<std::endl;
        return os;
    }
};

class NPC {
    std::string name;

public:
    explicit NPC(std::string name)
        : name(std::move(name)){
    }
    virtual ~NPC()=default;
    virtual void sayStuff() {
        std::cout<<"Hello!"<<std::endl;
    }

    [[nodiscard]] std::string get_name() const {
        return name;
    }
    friend std::ostream& operator<<(std::ostream &os, const NPC &npc) {
        os<<npc.name<<std::endl;
        return os;
    }
};

class Animal : public NPC {
    Item item;
    std::string catchphrase;
public:
    Animal(const std::string &name,const Item &item,std::string catchphrase)
        : NPC(name),
          item(item),
          catchphrase(std::move(catchphrase)){
    }

    void sayStuff() override {
        std::cout<<get_name()<<": "<<catchphrase<<std::endl;
    }

    static bool giveItem() {
        if (rand()%4==0)
            return true;
        return false;
    }

    [[nodiscard]] Item get_item() const {
        return item;
    }

    [[nodiscard]] std::string get_catchphrase() const {
        return catchphrase;
    }
    friend std::ostream& operator<<(std::ostream &os, const Animal &animal) {
        os<<animal.get_name()<<std::endl;
        os<<animal.get_catchphrase()<<std::endl;
        os<<animal.get_item()<<std::endl;
        return os;
    }
};

enum class Phase {
    Morning,
    Afternoon,
    Evening
};
std::vector<std::string> days {"Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday","Sunday"};
class GameEngine {
    static GameEngine *instance;
    int crtDay;
    Phase phase;
    GameEngine(int crtDay, Phase phase)
    : crtDay(crtDay), phase(phase) {}
    void changeDays() {
        ++crtDay;
        phase=Phase::Morning;
    }

public:
    static GameEngine* getInstance() {
        if (instance==nullptr) {
            instance=new GameEngine(0, Phase::Morning);
        }
        return instance;
    }
    GameEngine(const GameEngine&)=delete;
    GameEngine& operator=(const GameEngine&)=delete;
    [[nodiscard]] int get_crt_day() const {
        return crtDay;
    }

    [[nodiscard]] Phase get_phase() const {
        return phase;
    }

    void set_phase(Phase phase) {
        this->phase = phase;
    }
    void changePhase() {
        if (phase == Phase::Morning) phase = Phase::Afternoon;
        else if (phase == Phase::Afternoon) phase = Phase::Evening;
        else
            changeDays();
    }
};

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

    bool hasPluckSword() {
        for (int i=0; i<items.size(); i++) {
            if (items[i].get_effect()==effectType::multiplyGuts)
                return true;
        }
        return false;
    }
    bool hasGlasses() {
        for (int i=0; i<items.size(); i++) {
            if (items[i].get_effect()==effectType::multiplyIntelligence)
                return true;
        }
        return false;
    }
    bool hasPinkBow() {
        for (int i=0; i<items.size(); i++) {
            if (items[i].get_effect()==effectType::multiplyCharm)
                return true;
        }
        return false;
    }
    bool hasGreenMonster() {
        for (int i=0; i<items.size(); i++) {
            if (items[i].get_effect()==effectType::plantsGrowthBoost)
                return true;
        }
        return false;
    }


public:
    explicit Player(std::string &name)
        : name(std::move(name)),
          balance(100),
          crop_slots(5),
          prune(0),
          crops_used(0)

    {}

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    [[nodiscard]] int get_balance() const {
        return balance;
    }

    void set_balance(int val) {
        if (balance>INT_MAX-val)
            balance=INT_MAX;
        else
            balance+=val;
    }

    [[nodiscard]] int get_crop_slots() const {
        return crop_slots;
    }

    [[nodiscard]] int get_prune() const {
        return prune;
    }

    [[nodiscard]] std::vector<Item> get_items() const {
        return items;
    }

    [[nodiscard]] std::vector<std::string> get_seeds() const {
        return seeds;
    }

    void playSwordsWithMaster() {
        int base = 2 + (rand() % 6);
        int bonus = hasPluckSword() ? 2 : 0;
        stats.set_guts(base + bonus);
        GameEngine::getInstance()->changePhase();
    }
    void goToLibrary() {
        int base = 2 + (rand() % 6);
        int bonus = hasGlasses() ? 2 : 0;
        stats.set_intelligence(base + bonus);
        GameEngine::getInstance()->changePhase();
    }

    void workAtTheCafe() {
        int base = 2 + (rand() % 6);
        int bonus = hasPinkBow() ? 2 : 0;
        stats.set_charm(base + bonus);
        GameEngine::getInstance()->changePhase();
    }

    bool buySeeds(Seed const& seed, int howmany) {
        if (howmany==0){
            std::cout<<"Didn't buy any!\n";
            return false;
        }

        long long cost= howmany*seed.get_seed_cost();
        if (cost>balance) {
            std::cout<<"Not enough money :(";
            return false;
        }
        for (int i=0; i<howmany; i++) {
            seeds.push_back(seed.get_name());
        }
        balance=static_cast<int>(balance - cost);
        return true;
    }

    bool plantSeed(Seed const& seed) {
        if (crops_used>=crop_slots)
            return false;
        for (int i=0; i<seeds.size(); i++) {
            if (seeds[i]==seed.get_name()) {
                seeds.erase(seeds.begin()+i);
                plantedPlants.emplace_back(Plant(seed.get_name(),seed.get_seed_cost(),seed.get_seed_cost()*2));
                crops_used++;
                return true;
            }
        }
        return false;

    }
    int plantMultipleSeeds(Seed const& seed, int howmany) {
        if (howmany==0) {
            return 0;
        }
        int cntPlantedSeeds=0;
        for (int i=0; i<howmany; i++) {
            if (plantSeed(seed))
                cntPlantedSeeds++;
            else
                break;
        }
        return cntPlantedSeeds;
    }

    void growAllSeeds() {
        for (auto& pp : plantedPlants)
            pp.set_turns_since_planted();
    }

    int harvestAndSell() {
        int earnings=0;
        auto p=plantedPlants.begin();
        while (p!=plantedPlants.end()) {
            if (hasGreenMonster()) {
                if (p->get_turns_since_planted()>=3) {
                    earnings+=p->get_selling_price();
                    p=plantedPlants.erase(p);
                }
                else {++p;}
            }
            else
                if (p->get_turns_since_planted()>=6) {
                    earnings+=p->get_selling_price();
                    p=plantedPlants.erase(p);
                }
                else {++p;}
        }
        set_balance(earnings);
        return earnings;
    }

    bool buyCropSlot(int cost, int howmany) {
        if (howmany==0) {
            return false;
        }
        if (crop_slots>(100-howmany))
            return false;
        if (cost*howmany>balance) {
            return false;
        }
        set_balance((-1)*cost*howmany);
        crop_slots+=howmany;
        return true;
    }

    bool buyPrune(int howmany, const Prune &prunedecumparat) {
        if (howmany==0) { return false; }
        if (prunedecumparat.get_selling_price()*howmany>balance) {
            return false;
        }
        balance-=prunedecumparat.get_selling_price()*howmany;
        prune+=howmany;
        return true;
    }

    bool sellPrune(int howmany, const Prune &prunedevandut) {
        if (howmany==0) { return false; }
        if (howmany>prune) {
            std::cout<<"You don't have that many prune :(";
            return false;
        }
        set_balance((howmany)*(prunedevandut.get_selling_price()));
        prune-=howmany;
        return true;
    }

    void obtainItem(const Item &item) {
        items.push_back(item);
    }
    [[nodiscard]] bool checkVictory() const {
        if (stats.get_intelligence() >= 100) return true;
        if (stats.get_guts() >= 100) return true;
        if (stats.get_charm() >= 100) return true;
        if (get_balance() >= INT_MAX) return true;
        return false;
    }

    void display_stats(const Prune &prunebai) const{
        std::cout<<get_name()<<"'s stats:\n";
        std::cout<<"Guts: "<<stats.get_guts()<<"| Intelligence: "<<stats.get_intelligence()<<"| Charm"<<stats.get_charm()<<std::endl;
        std::cout<<"Balance: "<<balance<<std::endl;
        std::cout<<"Prune: "<<prune<<std::endl;
        std::cout<<"Prune Buiyng Price (Sunday Only): "<<prunebai.get_buying_price()<<std::endl;
        std::cout<<"Prune SellingPrice: "<<prunebai.get_selling_price()<<std::endl;
        std::cout<<"Crop Slots: "<<crop_slots<<std::endl;
        std::cout<<"Crops Used:"<<crops_used<<std::endl;

    }
    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os<<player.name<<std::endl;
        os<<player.balance<<std::endl;
        os<<player.crop_slots<<std::endl;
        os<<player.crops_used<<std::endl;
        return os;
    }
};

class prune_vendor : public NPC {
public:
    explicit prune_vendor(const std::string &name)
        : NPC(name) {
    }

    void sayStuff() override{
        std::cout<<get_name()<<" the prune vendor: Good greetings, esteemed citizen! I hear you would you like to purchase some prune?\nThey come at a great price and can be sold at an even greater one,\n but I would advise you to still be wise when making any kind of investment...\n";
    }
};

bool isSunday(int day) {
    return day%7==6;
}

void print_title() {
    std::cout<<"Welcome to Ferma Animalelor!\n";
}

void print_menu() {
    std::cout << "\nActions (choose number):\n";
    std::cout << "1. Read at library (gain intelligence)\n";
    std::cout << "2. Play swords with Farm Swordmaster (gain guts)\n";
    std::cout << "3. Work at cafe (earn charm & money)\n";
    std::cout << "4. Buy seeds\n";
    std::cout << "5. Plant seed from inventory\n";
    std::cout << "6. Buy crop slots (cost $100/slot)\n";
    std::cout << "7. Talk to someone (25% chance to get an item)\n";
    std::cout << "8. Buy prune (Sunday only)\n";
    std::cout << "9. Sell prune (Mon-Sat)\n";
    std::cout << "10. Exit\n";
}
GameEngine* GameEngine::instance = nullptr;
int main() {
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    print_title();
    std::cout<<"What's your name?\n";
    std::string name;
    std::cin>>name;

    Player player(name);
    std::cout<<"Hello, "<<player.get_name()<<"!\nYour fresh new start at Ferma Animalelor has just begun! Here, have 100$ and 5 crops...on the house ;)\n";

    std::vector<Seed> seeds = {
        {"Turnip", 5},
        {"Carrot", 8},
        {"Wheat", 10},
        {"Tomato", 12}
    };

    Item PinkBow("Pink Bow",effectType::multiplyCharm);
    Item Glasses("Glasses",effectType::multiplyIntelligence);
    Item PluckSword("Pluck Sword",effectType::multiplyGuts);
    Item GreenMonster("Green Monster",effectType::plantsGrowthBoost);

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
        int day=GameEngine::getInstance()->get_crt_day();
        auto phase=GameEngine::getInstance()->get_phase();
        std::cout<<"--- Day "<<day<<" "<<days[day%7]<<" ";
        if (phase==Phase::Afternoon) std::cout<<"Afternoon"<<std::endl;
        else if (phase==Phase::Morning) std::cout<<"Morning"<<std::endl;
        else std::cout<<"Evening";
        std::cout<<" ---"<<std::endl;
        player.display_stats(bursaprunelor);
        print_menu();
        int choice;
        std::cout<<"What do you want to do?\n";
        std::cin>>choice;
        switch(choice) {
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
            case 4:
                std::cout<<"How many seeds would you like to buy and what kind? [a number and 0-3]\n";
                int howmany,seedid;
                std::cin>>howmany>>seedid;
                player.buySeeds(seeds[seedid],howmany);
                std::cout<<"Thanks for shopping!\n";
                break;
            case 5:
                std::cout<<"How many seeds would you like to plant and what kind [a number and 0-3]?\n";
                std::cin>>howmany>>seedid;
                if (howmany<=1)
                    player.plantSeed(seeds[seedid]);
                else
                    player.plantMultipleSeeds(seeds[seedid],howmany);
                std::cout<<"Thanks for planting!\n";
                break;
            case 6:
                std::cout<<"How many crops would you like to buy?\n";
                std::cin>>howmany;
                player.buyCropSlot(100,howmany);
                break;
            case 7:
                std::cout<<"Who would you like to talk to? Enter a number 0-3]\n";
                std::cin>>howmany;
                animals[howmany].sayStuff();
                if (animals[howmany].giveItem())
                    player.obtainItem(animals[howmany].get_item());
                break;
            case 8:
                if (isSunday(day)) {
                    pruneSella.sayStuff();
                    std::cout<<"Cate prune vrei?\n";
                    std::cin >> howmany;
                    player.buyPrune(howmany,bursaprunelor);
                }
                else
                    std::cout<<"Nu ai voie!\n";
            case 9:
                if (!isSunday(day)) {
                    std::cout<<"Cate vinzi?\n";
                    std::cin>>howmany;
                    player.sellPrune(howmany,bursaprunelor);
                }
                else
                    std::cout<<"Nu ai voie!\n";
                break;
            case 10:
                std::cout<<"aia e.\n";
                exit(0);

        }
    }
    std::cout<<"Bv, ai castigat, hai pa.\n";

    return 0;

}
