#include "Echo.h"
Echo::Echo():ArgumentCommand(){}
std::optional<std::string> Echo::execute() {
    return mArgument;
}
std::string Echo::getName() {
    return "echo";
}