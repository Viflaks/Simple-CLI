//
// Created by win11 on 3/1/2026.
//

#ifndef HEAD_H
#define HEAD_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Abstract classes/OptionCommand.h"
#include "../Exceptions/Exception.h"

class Head : public ArgumentCommand,public OptionCommand{
    public:
        Head(std::string& option);
        std::optional<std::string> execute() override;
        std::string getName() override;
};



#endif //HEAD_H
