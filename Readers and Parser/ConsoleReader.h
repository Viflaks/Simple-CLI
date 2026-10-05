//
// Created by win11 on 1/6/2026.
//

#ifndef CONSOLEREADER_H
#define CONSOLEREADER_H
#include "Reader.h"

class ConsoleReader:public Reader{
    public:
        ConsoleReader():Reader(&std::cin){}
};



#endif //CONSOLEREADER_H
