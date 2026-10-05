//
// Created by win11 on 3/2/2026.
//

#ifndef BATCHINTERPRETER_H
#define BATCHINTERPRETER_H
#include "Interpreter.h"


class BatchInterpreter {
    public:
        BatchInterpreter(Interpreter* interpreter, std::shared_ptr<Writer>& writer,ConsoleReader* consoleReader);
        void run(std::string& fileName);
    private:
        Interpreter* mInterpreter;
        ConsoleReader* mConsoleReader;
        std::shared_ptr<Writer> mWriter;
        Executor* mExecutor;
};



#endif //BATCHINTERPRETER_H
