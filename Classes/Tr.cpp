#include "Tr.h"

#include "../Exceptions/Exception.h"

Tr::Tr(std::string &what, std::string with):ArgumentCommand(),
mWhat(what),
mWith(with){
    if (what[0]!='-' || what[1]!='"'|| what.back()!='"' || with[0]!='"' || with.back()!='"') throw Exception("Bad parameters for command tr");
}
std::optional<std::string> Tr::execute() {
    int pos=0;
    std::string with=mWith.substr(1,mWith.size()-2);
    std::string what=mWhat.substr(2,mWhat.size()-3);
    std::string endArgument=mArgument;
    pos=static_cast<int>(endArgument.find(what,pos));
    while(pos!=-1) {
        endArgument.replace(pos,what.size(),with);
        pos+=with.size();
        pos=static_cast<int>(endArgument.find(what,pos));
    }
    return endArgument;
}
std::string Tr::getName() {
    return "tr";
}

