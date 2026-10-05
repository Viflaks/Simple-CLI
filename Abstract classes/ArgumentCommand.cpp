//
// Created by win11 on 1/4/2026.
//

#include "ArgumentCommand.h"
ArgumentCommand::ArgumentCommand():
    Command(){
}
void ArgumentCommand::setArgument(std::string& argument) {
    mArgument = argument;
}
