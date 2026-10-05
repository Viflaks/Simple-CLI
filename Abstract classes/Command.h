//
// Created by win11 on 1/4/2026.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <optional>
#include <sstream>
#include <variant>

class Command {
    public:
        Command()=default;
        virtual std::optional<std::string> execute()=0;
        virtual std::string getName()=0;
        virtual void setArgument(std::string& argument){}
        virtual ~Command()=default;
};



#endif //COMMAND_H
