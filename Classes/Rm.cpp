#include "Rm.h"
Rm::Rm():ArgumentCommand() {
}
std::optional<std::string> Rm::execute() {
    std::fstream file(mArgument);
    if (!file.good()) throw ExceptionFileNotFound(mArgument);
    file.close();
    std::remove(mArgument.c_str());
    return std::nullopt;
}
std::string Rm::getName() {
    return "rm";
}

