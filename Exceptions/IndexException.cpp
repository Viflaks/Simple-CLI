#include "IndexException.h"
IndexException::IndexException(const std::string &message, int startIndex, int endIndex,std::string commandLine): Exception(message) {
    mMessage+="\n";
    mMessage+=commandLine;
    mMessage+="\n";
    for(int i=0;i<startIndex;i++) mMessage+=" ";
    for(int i=startIndex;i<endIndex;i++) mMessage+="^";
}
