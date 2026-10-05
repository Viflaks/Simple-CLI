#include "Executor.h"
Executor::Executor(Pipe *pipe, Parser *parser, Reader *reader,ConsoleReader* consoleReader,Interpreter* interpreter,std::shared_ptr<Writer>& writer):
mPipe(pipe),
mParser(parser),
mReader(reader),
mConsoleReader(consoleReader),
mInterpreter(interpreter),
mWriter(writer){
}
std::shared_ptr<Writer> Executor::generateWriter(std::vector<Token>& token) {
    if (token.size()>1 && (token[token.size()-2].getString()==">" || token[token.size()-2].getString()==">>")) {
        if (ExecutableCommands::getInstance()->getFileCommands().find(token[0].getString())!=ExecutableCommands::getInstance()->getFileCommands().end() && token[0].getString()!="batch") throw Exception("Invalid Command");
        if (ExecutableCommands::getInstance()->getIntCommands().find(token[0].getString())!=ExecutableCommands::getInstance()->getIntCommands().end()) throw Exception("Invalid Command");
        std::string redirect=token[token.size()-2].getString();
        std::string filename=token[token.size()-1].getString();
        token.resize(token.size()-2);
        if (redirect==">") return std::make_shared<FileWriter>(filename);
        return std::make_shared<FileWriterAppend>(filename);
    }
    return mWriter;
}
void Executor::executeLine(std::string& commandLine) {
    std::vector<Token> tokens = mParser->tokenize(commandLine);
    if (tokens.empty()) return;
    std::vector<std::vector<Token>> flowBase=mPipe->generateFlowBase(tokens);
    std::shared_ptr<Writer> writer=generateWriter(flowBase[flowBase.size()-1]);
    std::string argument = mParser->parseArgument(flowBase[0],mReader,mConsoleReader,flowBase.size(),commandLine);
    std::vector<std::shared_ptr<Command>> commands=mPipe->generateFlow(flowBase,mInterpreter,writer,mConsoleReader,commandLine);
    std::optional<std::string> output=argument;
    for (int i=0;i<commands.size();i++) {
        commands[i]->setArgument(*output);
        output=commands[i]->execute();
    }
    if (output) writer->write(*output);
    if (writer==mWriter && output) writer->write("\n");
}
