#include "Writer.h"
#include <ostream>
Writer::Writer(std::ostream *OutStream):mOutStream(OutStream) {
}
void Writer::write(const std::string& str) {
    *mOutStream<<str;
    mOutStream->flush();
}