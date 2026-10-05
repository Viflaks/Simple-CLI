#include "Batch.h"
Batch::Batch(Interpreter *interpreter, std::shared_ptr<Writer> &writer,ConsoleReader* consoleReader){
    mBatchInterpreter=new BatchInterpreter(interpreter,writer,consoleReader);
}
std::optional<std::string> Batch::execute() {
    mBatchInterpreter->run(mArgument);
    return std::nullopt;
}
std::string Batch::getName() {
    return "batch";
}