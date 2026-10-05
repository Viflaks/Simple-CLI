#include "BatchInterpreter.h"

#include "../Readers and Parser/FileReader.h"

BatchInterpreter::BatchInterpreter(Interpreter *interpreter,std::shared_ptr<Writer>& writer,ConsoleReader* consoleReader):
mInterpreter(interpreter),
mWriter(writer),
mConsoleReader(consoleReader),
mExecutor(nullptr){
}
void BatchInterpreter::run(std::string& fileName) {
    auto* fileReader=new FileReader(fileName);
    mExecutor=new Executor(new Pipe(),new Parser(),fileReader,mConsoleReader,mInterpreter,mWriter);
    while (!fileReader->getStream()->eof()) {
        std::string command=fileReader->readLine();
        try {
            mExecutor->executeLine(command);
        }
        catch (const Exception& e) {
            mWriter->write(e.what());
            mWriter->write("\n");
        }
    }
}