//
// Created by becbu on 12/8/2025.
//

#ifndef OOP_DAY_HPP
#define OOP_DAY_HPP
#include <vector>
#include <string>
class Day {
    //Atribute
    int day;
    int phase;
    bool changed;
    std::vector <std::string> dow={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    std::vector <std::string> phases={"Morning","Afternoon","Evening"};
    Day();

public:
    static Day &instance();

    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getPhase() const;
    [[nodiscard]] bool hasChanged() const;

    void changeDayPhase();

    [[nodiscard]] bool isSunday() const;
    void resetchange();

    std::string DayPhasetext();
};


#endif //OOP_DAY_HPP