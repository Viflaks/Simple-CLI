#include "Time.h"

const char *Time::getFormat() {
    return "%H:%M:%S";
}

std::string Time::getName() {
    return "time";
}