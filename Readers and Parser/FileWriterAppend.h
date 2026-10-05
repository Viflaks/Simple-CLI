//
// Created by win11 on 3/2/2026.
//

#ifndef FILEWRITERAPPEND_H
#define FILEWRITERAPPEND_H
#include <fstream>
#include <iostream>
#include "Writer.h"


class FileWriterAppend:public Writer {
    public:
        FileWriterAppend(std::string& fileName):Writer(new std::ofstream(fileName,std::ios::app)) {}
        ~FileWriterAppend() override {delete mOutStream;}

};



#endif //FILEWRITERAPPEND_H
