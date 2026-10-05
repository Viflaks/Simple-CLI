#include "Prompt.h"
#include "../Interpreter/Interpreter.h"
Prompt::Prompt(Interpreter *interpreter):ArgumentCommand(),
mInterpreter(interpreter){
}
std::optional<std::string> Prompt::execute() {
    mInterpreter->setPrompt(mArgument);
    return std::nullopt;
}
std::string Prompt::getName() {
    return "prompt";
}
