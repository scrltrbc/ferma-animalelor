//
// Created by becbu on 12/8/2025.
//

#include "../Headers/Day.hpp"

Day::Day():day(1), phase(0), changed(false){}

Day & Day::instance() {
    static Day instance;
    return instance;
}

int Day::getDay() const {
    return day;
}

int Day::getPhase() const {
    return phase;
}

bool Day::hasChanged() const {
    return changed;
}
void Day::changeDayPhase() {
    if (phase < 2)
        phase++;
    else {
        phase=0;
        day++;
    }
    changed = true;
}

bool Day::isSunday() const{
    return !(day%7);
}


void Day::resetchange() {
    changed = false;
}

std::string Day::DayPhasetext() {
    return "-Day "+std::to_string(day)+"|"+dow[day%7]+" "+phases[phase]+"-";
}
