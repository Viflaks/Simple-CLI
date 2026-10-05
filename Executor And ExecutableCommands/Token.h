//
// Created by win11 on 3/3/2026.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>


class Token {
    public:
        Token() : mString(""), mIndex(-1) {}
        Token(std::string string,int index):mString(string),mIndex(index){};
        std::string &getString(){return mString;}
        int getIndex(){return mIndex;}
    private:
    std::string mString;
    int mIndex;
};



#endif //TOKEN_H
