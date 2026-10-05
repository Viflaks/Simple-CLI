#include "Parser.h"
#include "ConsoleReader.h"
#include "FileReader.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/IndexException.h"
std::vector<Token> Parser::tokenize(std::string command) {
    if (command.size()>512) command=command.substr(0,512);
    std::vector<Token> tokens;
    std::string token;
    int index=0;
    for (int i=0;i<command.size();i++) {
        if (token.empty()) index=i;
        char c=command[i];
        if (isspace(c)) {
            if (!token.empty()) {
                tokens.emplace_back(token,index);
                token.clear();
            }
        }
        else if (c=='|') {
            if (!token.empty()) tokens.emplace_back(token,index);
            token="|";
            tokens.emplace_back(token,i);
            token.clear();
        }
        else if (c=='<') {
            if (!token.empty()) tokens.emplace_back(token,index);
            token="<";
            tokens.emplace_back(token,i);
            token.clear();
        }
        else if (c=='>') {
            if (!token.empty()) tokens.emplace_back(token,index);
            token=">";
            index=i;
            if (i<command.size()-1 && command[i+1]=='>') token.push_back(command[++i]);
            tokens.emplace_back(token,index);
            token.clear();
        }
        else {
            if (c=='"') {
                token.push_back(command[i]);
                i+=1;
                while (command[i]!='"' && i<command.size()) {
                    token.push_back(command[i]);
                    i+=1;
                }
                if (i<command.size()) token.push_back('"');
            }
            else {
                token.push_back(command[i]);
            }
        }
    }
    if (!token.empty()) tokens.emplace_back(token,index);
    if (!tokens.empty() && tokens.back().getString()=="|") throw IndexException("Invalid commandLine",command.size()-1,command.size(),command);
    return tokens;
}
std::string Parser::parseArgument(std::vector<Token>& command,Reader*r,ConsoleReader*cR, int size,std::string& commandLine) {
    if (ExecutableCommands::getInstance()->getTimeCommands().find(command[0].getString())!=ExecutableCommands::getInstance()->getTimeCommands().end()) {
        if (command.size()!=1)
            throw Exception("Time commands can't have arguments");
        return "";
    }
    if (ExecutableCommands::getInstance()->getFileCommands().find(command[0].getString())!=ExecutableCommands::getInstance()->getFileCommands().end()) {
        if (command.size()!=2)
            throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        if (command[1].getString()[0]=='"' || command[1].getString()[command[1].getString().size()-1]=='"')
            throw IndexException("Invalid argument style for start file type command",command[1].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        std::string argument=command[1].getString();
        command.resize(1);
        return argument;
    }
    if (ExecutableCommands::getInstance()->getIntCommands().find(command[0].getString())!=ExecutableCommands::getInstance()->getIntCommands().end()) {
        if (command.size()!=2)
            throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        if (command[1].getString()[0]!='"' || command[1].getString()[command[1].getString().size()-1]!='"')
            throw IndexException("Invalid argument style for start prompt type command",command[1].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        return parseQuotedArgument(command,1);
    }
    int argIndex=-1;
    bool redirect=false;
    for (int i=1;i<command.size();i++) {
        if (command[i].getString()[0]!='-') {
            argIndex=i;
            if (command[i].getString()=="<") redirect=true;
            break;
        }
        if (command[0].getString()=="tr") break;
    }
    if (redirect) {
        for (int i=argIndex;i<command.size()-1;i++) command[i]=command[i+1];
        command.resize(command.size()-1);
    }
    if (ExecutableCommands::getInstance()->getArgCommands().find(command[0].getString())!=ExecutableCommands::getInstance()->getArgCommands().end()) {
        if (argIndex==-1) {
            if (command[0].getString()=="echo" && command.size()==1) return cR->readLines();
            if (command.size()!=1) throw IndexException("Command "+command[0].getString()+" does not take options",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        }
        if (command.size()!=2)  throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        if (redirect) {
            if (command[0].getString()=="echo" && command.size()==2) return parseFileArgument(command,argIndex);
        }
        if (command[0].getString()=="echo" && command.size()==2) return parseLineArgument(command,argIndex);
    }
    if (ExecutableCommands::getInstance()->getOptCommands().find(command[0].getString())!=ExecutableCommands::getInstance()->getOptCommands().end()) {
        if (argIndex==-1) {
            if (command[0].getString()=="head" && command.size()==2) return cR->readLines();
            if (command[0].getString()=="wc" && command.size()==2) return cR->readLines();
            if (command[0].getString()=="tr" && command.size()>=2 && command.size()<=3) return cR->readLines();
            throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        }
        if (redirect) {
            if (command[0].getString()=="head" && command.size()==3 && argIndex==2) return parseFileArgument(command,argIndex);
            if (command[0].getString()=="wc" && command.size()==3 && argIndex==2) return parseFileArgument(command,argIndex);
            if (command[0].getString()=="tr" && (command.size()==3 || command.size()==4) && argIndex==1) return parseFileArgument(command,argIndex);
            throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
        }
        if (command[0].getString()=="head" && command.size()==3 && argIndex==2) return parseLineArgument(command,argIndex);
        if (command[0].getString()=="wc" && command.size()==3 && argIndex==2) return parseLineArgument(command,argIndex);
        if (command[0].getString()=="tr" && (command.size()==3 || command.size()==4) && argIndex==1) return parseLineArgument(command,argIndex);
        throw IndexException("Wrong number of arguments",command[0].getIndex(),command.back().getIndex()+command.back().getString().size(),commandLine);
    }
    throw IndexException("Unknown command name: "+command[0].getString(),command[0].getIndex(),command[0].getString().size(),commandLine);
}
std::string Parser::parseFileArgument(std::vector<Token>& token, int index) {
    auto* fReader=new FileReader(token[index].getString());
    for (int i=index;i<token.size()-1;i++) token[i]=token[i+1];
    token.resize(token.size()-1);
    return fReader->readLines();
}
std::string Parser::parseQuotedArgument(std::vector<Token>& token,int index) {
    std::string argument=token[index].getString().substr(1,token[index].getString().size()-2);
    for (int i=index;i<token.size()-1;i++) token[i]=token[i+1];
    token.resize(token.size()-1);
    return argument;
}
std::string Parser::parseLineArgument(std::vector<Token>& token,int index) {
    if (token[index].getString()[0]=='"' && token[1].getString()[token[index].getString().size()-1]=='"') return parseQuotedArgument(token,index);
    if (token[index].getString()[0]=='"' || token[1].getString()[token[index].getString().size()-1]=='"')
        throw Exception("Invalid argument");
    return parseFileArgument(token,index);
}