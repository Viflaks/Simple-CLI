//
// Created by win11 on 3/1/2026.
//

#ifndef TRUNCATE_H
#define TRUNCATE_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/ExceptionFileNotFound.h"
class Truncate:public ArgumentCommand {
    public:
        Truncate();
        std::optional<std::string> execute() override;
        std::string getName() override;

};



#endif //TRUNCATE_H
