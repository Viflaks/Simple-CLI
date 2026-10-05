//
// Created by win11 on 1/13/2026.
//

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>


class Exception:public std::exception{
    public:
        Exception(std::string message):mMessage(message){}
        virtual const char *what() const noexcept override{return mMessage.c_str();}
    protected:
        std::string mMessage;
};



#endif //EXCEPTION_H
