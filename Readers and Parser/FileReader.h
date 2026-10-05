//
// Created by win11 on 1/6/2026.
//

#ifndef FILEREADER_H
#define FILEREADER_H
#include "Reader.h"
#include <fstream>
#include "../Exceptions/ExceptionFileNotFound.h"
class FileReader:public Reader{
    public:
        FileReader(const std::string& fileName):Reader(new std::ifstream(fileName)){if (!mInStream->good()) throw ExceptionFileNotFound(fileName);}
        ~FileReader() override {delete mInStream;}
        virtual int decSize() override {return 0;}
};



#endif //FILEREADER_H
