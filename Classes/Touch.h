//
// Created by win11 on 1/6/2026.
//

#ifndef TOUCH_H
#define TOUCH_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/ExceptionFileAlreadyExists.h"
class Touch:public ArgumentCommand{
    public:
        Touch():ArgumentCommand(){}
        std::optional<std::string> execute() override;
        std::string getName() override;
};



#endif //TOUCH_H
