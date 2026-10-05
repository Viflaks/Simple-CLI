//
// Created by win11 on 2/28/2026.
//

#ifndef WRITER_H
#define WRITER_H
#include <string>


class Writer {
    public:
        Writer(std::ostream *OutStream);
        virtual ~Writer()=default;
        virtual void write(const std::string& str);
    protected:
        std::ostream *mOutStream;
};



#endif //WRITER_H
