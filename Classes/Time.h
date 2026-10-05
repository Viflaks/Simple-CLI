#ifndef TIME_H
#define TIME_H
#include "../Abstract classes/TimeCommand.h"

class Time:public TimeCommand{
    public:
        Time()=default;
        const char* getFormat() override;
        std::string getName() override;
};



#endif //TIME_H
