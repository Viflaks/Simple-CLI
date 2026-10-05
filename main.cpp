#include <iostream>
#include <optional>
#include "Interpreter/Interpreter.h"
int main() {
    std::shared_ptr<Writer> writer=std::make_shared<ConsoleWriter>();
    auto* interpreter=new Interpreter(new ConsoleReader(),writer,new Parser(),new Pipe());
    interpreter->run();
    return 0;
}
