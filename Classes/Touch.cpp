//
// Created by win11 on 1/6/2026.
//
#include "Touch.h"


std::optional<std::string> Touch::execute() {
    std::ifstream file(mArgument);
    if (file.good()) throw ExceptionFileAlreadyExists(mArgument);
    std::ofstream output(mArgument);
    return std::nullopt;
}
std::string Touch::getName() {
    return "touch";
}