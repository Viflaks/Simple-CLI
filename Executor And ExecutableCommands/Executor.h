//
// Created by win11 on 3/2/2026.
//

#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "../Readers and Parser/Parser.h"
#include "../Readers and Parser/Pipe.h"
#include "../Readers and Parser/Writer.h"
#include "../Readers and Parser/Reader.h"
#include "ExecutableCommands.h"
#include "../Readers and Parser/ConsoleReader.h"


class Executor {
    public:
        Executor(Pipe* pipe,Parser* parser,Reader* reader,ConsoleReader* consoleReader,Interpreter* interpreter,std::shared_ptr<Writer>& writer);
        void executeLine(std::string& commandLine);
        std::shared_ptr<Writer> generateWriter(std::vector<Token>& token);
    private:
        Pipe* mPipe;
        Parser* mParser;
        Reader* mReader;
        ConsoleReader* mConsoleReader;
        std::shared_ptr<Writer> mWriter;
        Interpreter* mInterpreter;
};



#endif //EXECUTOR_H
