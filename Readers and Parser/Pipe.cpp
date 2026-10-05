#include "Pipe.h"

#include "../Classes/Batch.h"
#include "../Exceptions/IndexException.h"
std::vector<std::vector<Token>> Pipe::generateFlowBase(std::vector<Token>& tokens) {
    std::vector<std::vector<Token>> flowBase;
    std::vector<Token> command;
    for(int i=0;i<tokens.size();i++){
        while(i<tokens.size() && tokens[i].getString()!="|") {
            command.push_back(tokens[i++]);
        }
        flowBase.push_back(command);
        command.clear();
    }
    return flowBase;
}
std::vector<std::shared_ptr<Command>> Pipe::generateFlow(std::vector<std::vector<Token>> flowBase,Interpreter* interpreter,std::shared_ptr<Writer>& writer,ConsoleReader*consoleReader,std::string& commandLine) {
    std::vector<std::shared_ptr<Command>> commands;
    std::shared_ptr<Command> command;
    std::string token;
    for(int i=0;i<flowBase.size();i++) {
        token=flowBase[i][0].getString();
        if (ExecutableCommands::getInstance()->getTimeCommands().find(token)!=ExecutableCommands::getInstance()->getTimeCommands().end()) {
            if (flowBase[i].size()>1 || i!=0)
                throw IndexException("Command without input can only be at the start of pipe",flowBase[i][0].getIndex(),flowBase[i][0].getString().size()+flowBase[i][0].getIndex(),commandLine);
            if (token=="time") command=std::make_shared<Time>();
            if (token=="date") command=std::make_shared<Date>();
        }
        else if (ExecutableCommands::getInstance()->getFileCommands().find(token)!=ExecutableCommands::getInstance()->getFileCommands().end()) {
            if (flowBase[i].size()>1 || i!=flowBase.size()-1)
                throw IndexException("Command without output can only be at the start of pipe",flowBase[i][0].getIndex(),flowBase[i][0].getString().size()+flowBase[i][0].getIndex(),commandLine);
            if (token=="touch") command=std::make_shared<Touch>();
            if (token=="rm") command=std::make_shared<Rm>();
            if (token=="truncate") command=std::make_shared<Truncate>();
            if (token=="batch") command=std::make_shared<Batch>(interpreter,writer,consoleReader);
        }
        else if (ExecutableCommands::getInstance()->getIntCommands().find(token)!=ExecutableCommands::getInstance()->getIntCommands().end()) {
            if (flowBase[i].size()>1 || i!=flowBase.size()-1) throw IndexException("Command without output can only be at the start of pipe",flowBase[i][0].getIndex(),flowBase[i][0].getString().size()+flowBase[i][0].getIndex(),commandLine);
            if (token=="prompt") command=std::make_shared<Prompt>(interpreter);
        }
        else if (ExecutableCommands::getInstance()->getArgCommands().find(token)!=ExecutableCommands::getInstance()->getArgCommands().end()) {
            if (flowBase[i].size()>1) throw IndexException("Wrong number of options/parameters for command : "+token,flowBase[i][1].getIndex(),flowBase[i].back().getString().size()+flowBase[i].back().getIndex(),commandLine);
            if (token=="echo") command=std::make_shared<Echo>();
        }
        else if (ExecutableCommands::getInstance()->getOptCommands().find(token)!=ExecutableCommands::getInstance()->getOptCommands().end()) {
            if (flowBase[i].size()==2) {
                if (token=="wc") command=std::make_shared<Wc>(flowBase[i][1].getString());
                if (token=="head") command=std::make_shared<Head>(flowBase[i][1].getString());
                if (token=="tr") command=std::make_shared<Tr>(flowBase[i][1].getString());
            }
            else if (flowBase[i].size()==3) {
                if (token=="tr") command=std::make_shared<Tr>(flowBase[i][1].getString(),flowBase[i][2].getString());
                else throw IndexException("Wrong number of options/parameters for command : "+token,flowBase[i][1].getIndex(),flowBase[i].back().getString().size()+flowBase[i].back().getIndex(),commandLine);
            }
            else throw IndexException("Wrong number of options/parameters for command : "+token,flowBase[i][0].getIndex(),flowBase[i].back().getString().size()+flowBase[i].back().getIndex(),commandLine);
        }
        else throw IndexException("Unknown command : "+token,flowBase[i][0].getIndex(),flowBase[i][0].getString().size()+flowBase[i][0].getIndex(),commandLine);
        commands.push_back(command);
    }
    return commands;
}