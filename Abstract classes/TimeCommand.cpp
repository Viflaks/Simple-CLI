//
// Created by win11 on 1/5/2026.
//

#include "TimeCommand.h"
std::optional<std::string> TimeCommand::execute() {
    std::time_t now;
    std::stringstream ss;
    time(&now);
    ss<<std::put_time(std::localtime(&now),getFormat());
    return ss.str();
}