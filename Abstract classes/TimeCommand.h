//
// Created by win11 on 1/5/2026.
//

#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H
#include "Command.h"


class TimeCommand:public Command{
    public:
        virtual std::optional<std::string> execute() override;
        virtual const char* getFormat()=0;
};



#endif //TIMECOMMAND_H
