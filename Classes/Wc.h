//
// Created by win11 on 1/4/2026.
//

#ifndef WC_H
#define WC_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Abstract classes/OptionCommand.h"
#include "../Exceptions/Exception.h"
class Wc:public ArgumentCommand,public OptionCommand{
    public:
        Wc(std::string& operation);
        std::optional<std::string> execute() override;
        std::string getName() override;
};



#endif //WC_H
