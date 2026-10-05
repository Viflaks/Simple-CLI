#include "ExecutableCommands.h"
ExecutableCommands* ExecutableCommands::instance=nullptr;
ExecutableCommands *ExecutableCommands::getInstance() {
    if (!instance) instance=new ExecutableCommands();
    return instance;
}
ExecutableCommands::ExecutableCommands() {
    mArgCommands.insert("echo");
    mFileCommands.insert("touch");
    mFileCommands.insert("batch");
    mFileCommands.insert("truncate");
    mFileCommands.insert("rm");
    mOptCommands.insert("wc");
    mOptCommands.insert("head");
    mOptCommands.insert("tr");
    mTimeCommands.insert("date");
    mTimeCommands.insert("time");
    mIntCommands.insert("prompt");
}
std::set<std::string>& ExecutableCommands::getTimeCommands() {
    return mTimeCommands;
}
std::set<std::string>& ExecutableCommands::getArgCommands() {
    return mArgCommands;
}
std::set<std::string>& ExecutableCommands::getOptCommands() {
    return mOptCommands;
}
std::set<std::string>& ExecutableCommands::getIntCommands() {
    return mIntCommands;
}
std::set<std::string>& ExecutableCommands::getFileCommands() {
    return mFileCommands;
}
