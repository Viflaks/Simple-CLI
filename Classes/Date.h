//
// Created by win11 on 1/4/2026.
//

#ifndef DATE_H
#define DATE_H
#include "../Abstract classes/TimeCommand.h"

class Date:public TimeCommand{
public:
    Date()=default;
    const char* getFormat() override;
    std::string getName() override;
};


#endif //DATE_H
