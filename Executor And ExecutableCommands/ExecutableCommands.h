#ifndef EXECUTABLECOMMANDS_H
#define EXECUTABLECOMMANDS_H


#include <set>
#include <string>
class ExecutableCommands {
    public:
        static ExecutableCommands* getInstance();
        std::set<std::string>& getTimeCommands();
        std::set<std::string>& getArgCommands();
        std::set<std::string>& getOptCommands();
        std::set<std::string>& getIntCommands();
        std::set<std::string>& getFileCommands();
    private:
        ExecutableCommands();
        static ExecutableCommands* instance;
        std::set<std::string> mTimeCommands;
        std::set<std::string> mArgCommands;
        std::set<std::string> mOptCommands;
        std::set<std::string> mIntCommands;
        std::set<std::string> mFileCommands;
};



#endif
