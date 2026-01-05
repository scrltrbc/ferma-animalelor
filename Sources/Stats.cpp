//
// Created by becbu on 12/5/2025.
//

#include "../Headers/Stats.hpp"
#include <cmath>
//Getters&Setters
int Stats::get_guts() const {
    return guts;
}

int Stats::get_intelligence() const {
    return intelligence;
}

int Stats::get_charm() const {
    return charm;
}

void Stats::set_guts(int val) {
    guts = std::min(100, guts + val);
}

void Stats::set_intelligence(int val) {
    intelligence = std::min(100, intelligence + val);
}

void Stats::set_charm(int val) {
    charm = std::min(100, charm + val);
}


