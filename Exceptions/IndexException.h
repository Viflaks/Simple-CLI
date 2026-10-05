//
// Created by win11 on 3/3/2026.
//

#ifndef INDEXEXCEPTION_H
#define INDEXEXCEPTION_H
#include "Exception.h"


class IndexException:public Exception{
    public:
        IndexException(const std::string & message,int startIndex,int endIndex,std::string commandLine);
};



#endif //INDEXEXCEPTION_H
