//
// Created by becbu on 12/5/2025.
//

#ifndef OOP_STATS_HPP
#define OOP_STATS_HPP

#include <algorithm>
class Stats {
    //Atribute
    int guts;
    int intelligence;
    int charm;

public:
    //Constructori&Destructor
    Stats() : guts(0), intelligence(0), charm(0) {}
    ~Stats() = default;

    [[nodiscard]] int get_guts() const;
    [[nodiscard]] int get_intelligence() const;
    [[nodiscard]] int get_charm() const;

    void set_guts(int val);
    void set_intelligence(int val);
    void set_charm(int val);
};
#endif //OOP_STATS_HPP