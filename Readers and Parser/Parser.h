#ifndef PARSER_H
#define PARSER_H
#include "Reader.h"
#include "Pipe.h"
#include "../Abstract classes/Command.h"
#include "../Executor And ExecutableCommands/ExecutableCommands.h"
#include "FileWriterAppend.h"
#include <set>
#include "../Executor And ExecutableCommands/Token.h"
#include "ConsoleReader.h"

class Parser {
    public:
        Parser()=default;
        std::string parseArgument(std::vector<Token>& command,Reader*r,ConsoleReader*cR,int size,std::string& commandLine);
        std::string parseLineArgument(std::vector<Token>& token, int index);
        std::string parseFileArgument(std::vector<Token>& token, int index);
        std::string parseQuotedArgument(std::vector<Token>& token, int index);
        std::vector<Token> tokenize(std::string command);
        ~Parser()=default;
    private:
};



#endif //PARSER_H
