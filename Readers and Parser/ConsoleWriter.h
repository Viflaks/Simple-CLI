//
// Created by win11 on 2/28/2026.
//

#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H
#include <iostream>
#include "Writer.h"


class ConsoleWriter:public Writer {
    public:
        ConsoleWriter():Writer(&std::cout){
            mOutStream=&std::cout;
        }
};



#endif //CONSOLEWRITER_H
