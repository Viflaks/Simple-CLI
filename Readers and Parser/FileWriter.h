//
// Created by win11 on 2/28/2026.
//

#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <fstream>
#include <iostream>
#include "Writer.h"


class FileWriter:public Writer {
    public:
        FileWriter(std::string& fileName):Writer(new std::ofstream(fileName)) {}
        ~FileWriter() override {delete mOutStream;}
};



#endif //FILEWRITER_H
