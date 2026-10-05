cmake_minimum_required(VERSION 3.31)
project(OO1project)

set(CMAKE_CXX_STANDARD 17)

add_executable(OO1project main.cpp
        "Abstract classes/ArgumentCommand.cpp"
        "Abstract classes/ArgumentCommand.h"
        Classes/Echo.cpp
        Classes/Echo.h
        Classes/Wc.cpp
        Classes/Wc.h
        Classes/Time.cpp
        Classes/Time.h
        Classes/Date.cpp
        Classes/Date.h
        "Readers and Parser/Reader.cpp"
        "Readers and Parser/Reader.h"
        "Readers and Parser/Parser.cpp"
        "Readers and Parser/Parser.h"
        "Abstract classes/Command.cpp"
        "Abstract classes/Command.h"
        "Abstract classes/TimeCommand.cpp"
        "Abstract classes/TimeCommand.h"
        "Readers and Parser/FileReader.h"
        "Readers and Parser/ConsoleReader.h"
        Classes/Touch.cpp
        Classes/Touch.h
        Exceptions/Exception.h
        "Readers and Parser/Pipe.cpp"
        "Readers and Parser/Pipe.h"
        "Executor And ExecutableCommands/ExecutableCommands.cpp"
        "Executor And ExecutableCommands/ExecutableCommands.h"
        Interpreter/Interpreter.cpp
        Interpreter/Interpreter.h
        "Readers and Parser/Writer.cpp"
        "Readers and Parser/Writer.h"
        "Readers and Parser/ConsoleWriter.h"
        "Readers and Parser/FileWriter.h"
        Classes/Prompt.cpp
        Classes/Prompt.h
        Classes/Truncate.cpp
        Classes/Truncate.h
        Classes/Rm.cpp
        Classes/Rm.h
        Classes/Head.cpp
        Classes/Head.h
        "Abstract classes/OptionCommand.cpp"
        "Abstract classes/OptionCommand.h"
        Classes/Tr.cpp
        Classes/Tr.h
        "Executor And ExecutableCommands/Executor.cpp"
        "Executor And ExecutableCommands/Executor.h"
        "Readers and Parser/FileWriterAppend.h"
        Classes/Batch.cpp
        Classes/Batch.h
        Interpreter/BatchInterpreter.cpp
        Interpreter/BatchInterpreter.h
        Exceptions/IndexException.cpp
        Exceptions/IndexException.h
        "Executor And ExecutableCommands/Token.h"
        Exceptions/ExceptionFileNotFound.h
        Exceptions/ExceptionFileAlreadyExists.h)
