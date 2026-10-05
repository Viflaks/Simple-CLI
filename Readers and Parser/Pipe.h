#ifndef PIPE_H
#define PIPE_H
#include <memory>

#include "../Abstract classes/Command.h"
#include <vector>

#include "ConsoleReader.h"
#include "../Classes/Echo.h"
#include "../Classes/Wc.h"
#include "../Classes/Time.h"
#include "../Classes/Date.h"
#include "../Classes/Touch.h"
#include "../Executor And ExecutableCommands/ExecutableCommands.h"
#include "../Classes/Prompt.h"
#include "ConsoleWriter.h"
#include "FileWriter.h"
#include "../Classes/Truncate.h"
#include "../Classes/Rm.h"
#include "../Classes/Head.h"
#include "../Classes/Tr.h"
#include "../Executor And ExecutableCommands/Token.h"
class Pipe {
    public:
        Pipe()=default;
        std::vector<std::vector<Token>> generateFlowBase(std::vector<Token>& tokens);
        std::vector<std::shared_ptr<Command>> generateFlow(std::vector<std::vector<Token>> flowBase,Interpreter* interpreter,std::shared_ptr<Writer>& writer,ConsoleReader*consoleReader,std::string& commandLine);
        ~Pipe()=default;
};



#endif //PIPE_H
