#include "Interpreter.h"
Interpreter::Interpreter(ConsoleReader*reader,std::shared_ptr<Writer>& writer,Parser*parser,Pipe* pipe):
mReader(reader),
mParser(parser),
mPipe(pipe),
mWriter(writer){
    mExecutor=new Executor(mPipe,mParser,mReader,mReader,this,mWriter);
}
void Interpreter::run() {
    std::cout<<"$ ";
    std::string command=mReader->readLine();
    while (!std::cin.eof()) {
        try {
            mExecutor->executeLine(command);
        }
        catch (const Exception& e) {
            std::cout<<e.what()<<"\n";
        }
        std::cout<<mPrompt<<" ";
        command=mReader->readLine();
    }
}
void Interpreter::setPrompt(std::string prompt) {
    mPrompt=prompt;
}