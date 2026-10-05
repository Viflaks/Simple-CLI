#include "Head.h"

Head::Head(std::string &option):
ArgumentCommand(),
OptionCommand(option){
}
std::optional<std::string> Head::execute() {
    if (mOption.substr(0,2)!="-n") throw Exception("Invalid option given for Command: "+getName());
    if (mOption.size()>7) throw Exception("Invalid option given for Command: "+getName());
    try {
        int number = std::stoi(mOption.substr(2,mOption.size()-2));
        std::string output;
        int c=0;
        for (int i=0;i<number;i++) {
            while (mArgument[c]!='\n' && c<mArgument.size())
                output += mArgument[c++];
            if (c==mArgument.size()) break;
            if (i<number-1) output += mArgument[c++];
        }
        return output;
    }
    catch(...) {
        throw Exception("Invalid option given for Command: "+getName());
    }
}
std::string Head::getName() {
    return "head";
}
