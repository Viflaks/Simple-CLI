#include "Wc.h"
#include <algorithm>
Wc::Wc(std::string &option):
    ArgumentCommand(),
    OptionCommand(option){
    if (mOption!="-w" && mOption!="-c") throw (Exception("Invalid option give for Command: wc"));
}
std::optional<std::string> Wc::execute() {
    int number;
    number = std::count_if(mArgument.begin(), mArgument.end(), [](unsigned char c){return std::isspace(c);});
    if (mOption=="-w") return std::to_string(number+1);
    if (mOption=="-c") return std::to_string(mArgument.size());
}
std::string Wc::getName() {
    return "wc";
}