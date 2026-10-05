//
// Created by win11 on 1/4/2026.
//

#ifndef READER_H
#define READER_H
#include <string>
#include <iostream>
#include <vector>
#include "../Exceptions/Exception.h"

class Reader {
    public:
        Reader(std::istream *inStream);
        virtual ~Reader()=default;
        std::string readLine();
        std::string readLines();
        std::istream* getStream();
        virtual int decSize(){return 1;}
    protected:
        std::istream *mInStream;
};



#endif //READER_H
