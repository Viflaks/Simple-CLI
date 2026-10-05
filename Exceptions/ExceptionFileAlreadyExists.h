//
// Created by win11 on 3/3/2026.
//

#ifndef EXCEPTIONFILEALREADYEXISTS_H
#define EXCEPTIONFILEALREADYEXISTS_H
#include "Exception.h"


class ExceptionFileAlreadyExists:public Exception {
    public:
        ExceptionFileAlreadyExists(std::string filename):Exception("File with name "+filename+" already exists"){}
};



#endif //EXCEPTIONFILEALREADYEXISTS_H
