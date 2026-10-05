//
// Created by win11 on 3/1/2026.
//

#ifndef TR_H
#define TR_H
#include "../Abstract classes/ArgumentCommand.h"


class Tr:public ArgumentCommand{
    public:
        Tr(std::string& what,std::string with="\"\"");
        std::optional<std::string> execute() override;
        std::string getName() override;
    private:
        std::string mWhat;
        std::string mWith;
};



#endif //TR_H
