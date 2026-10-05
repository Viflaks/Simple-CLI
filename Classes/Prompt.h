#ifndef PROMPT_H
#define PROMPT_H
#include "../Abstract classes/ArgumentCommand.h"
class Interpreter;


class Prompt:public ArgumentCommand {
    public:
        Prompt(Interpreter* interpreter);
        std::optional<std::string> execute() override;
        std::string getName() override;
    private:
        Interpreter* mInterpreter;
};



#endif //PROMPT_H
