//
// Created by win11 on 3/1/2026.
//

#ifndef OPTIONCOMMAND_H
#define OPTIONCOMMAND_H
#include "ArgumentCommand.h"


class OptionCommand:virtual public Command{
    public:
        OptionCommand(std::string& option);
    protected:
        std::string mOption;

};



#endif //OPTIONCOMMAND_H
