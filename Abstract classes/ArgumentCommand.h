//
// Created by win11 on 1/4/2026.
//

#ifndef ARGUMENTCOMMAND_H
#define ARGUMENTCOMMAND_H
#include "Command.h"
class ArgumentCommand:virtual public Command{
    public:
        ArgumentCommand();
        void setArgument(std::string& argument) override;
    protected:
        std::string mArgument;
};



#endif //ARGUMENTCOMMAND_H
