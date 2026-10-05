#include "Truncate.h"
Truncate::Truncate():ArgumentCommand() {
}
std::optional<std::string> Truncate::execute() {
    std::ifstream input(mArgument);
    if (!input.good()) throw ExceptionFileNotFound(mArgument);
    std::ofstream file(mArgument, std::ios::out);
    file.close();
    return std::nullopt;
}
std::string Truncate::getName() {
    return "truncate";
}