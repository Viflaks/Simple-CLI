#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "../Readers and Parser/ConsoleReader.h"
#include "../Readers and Parser/Parser.h"
#include "../Readers and Parser/Pipe.h"
#include "../Exceptions/Exception.h"
#include "../Executor And ExecutableCommands/Executor.h"
#include "../Classes/Prompt.h"

class Interpreter {
    public:
        Interpreter(ConsoleReader*reader,std::shared_ptr<Writer>& writer,Parser*parser,Pipe* pipe);
        void setPrompt(std::string prompt);
        void run();
    private:
        ConsoleReader *mReader;
        std::shared_ptr<Writer> mWriter;
        Parser *mParser;
        Pipe *mPipe;
        Executor *mExecutor;
        std::string mPrompt="$";
};



#endif //INTERPRETER_H
