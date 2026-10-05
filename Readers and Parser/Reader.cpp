#include "Reader.h"
#include <iostream>
Reader::Reader(std::istream *inStream):mInStream(inStream) {
}
std::string Reader::readLine() {
    std::string line;
    std::getline(*mInStream, line,'\n');
    return line;
}
std::string Reader::readLines() {
    std::string line;
    std::vector<std::string> set;
    while (!mInStream->eof()) {
        set.push_back(readLine());
    }
    for (int i=0;i<set.size()-decSize();i++) {
        line+=set[i];
        if (i!=set.size()-1-decSize()) line+="\n";
    }
    mInStream->clear();
    return line;
}
std::istream* Reader::getStream() {
    return mInStream;
}