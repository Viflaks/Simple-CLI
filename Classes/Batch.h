#ifndef BATCH_H
#define BATCH_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Interpreter/BatchInterpreter.h"

class Interpreter;

class Batch:public ArgumentCommand{
    public:
        Batch(Interpreter* interpreter,std::shared_ptr<Writer>& writer,ConsoleReader* consoleReader);
        std::optional<std::string> execute() override;
        std::string getName() override;
        ~Batch()=default;
    private:
    BatchInterpreter* mBatchInterpreter;

};



#endif //BATCH_H
