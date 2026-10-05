//
// Created by win11 on 3/3/2026.
//

#ifndef EXCEPTIONFILENOTFOUND_H
#define EXCEPTIONFILENOTFOUND_H
#include <string>

#include "Exception.h"


class ExceptionFileNotFound: public Exception {
    public:
        ExceptionFileNotFound(std::string fileName):Exception("File with name "+fileName+" not found"){}
};



#endif //EXCEPTIONFILENOTFOUND_H
