#ifndef RM_H
#define RM_H
#include "../Abstract classes/ArgumentCommand.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/ExceptionFileNotFound.h"
class Rm:public ArgumentCommand{
    public:
        Rm();
        std::optional<std::string> execute() override;
        std::string getName() override;
};



#endif //RM_H
