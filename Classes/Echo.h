//
// Created by win11 on 1/4/2026.
//

#ifndef ECHO_H
#define ECHO_H
#include "../Abstract classes/ArgumentCommand.h"


class Echo: public ArgumentCommand {
    public:
        Echo();
        std::optional<std::string> execute() override;
        std::string getName() override;
};



#endif //ECHO_H
