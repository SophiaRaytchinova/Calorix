#pragma once

#include <vector>
#include <string>

class CommandParser
{
public:
    static std::vector<std::string>
    split(
        const std::string& commandLine
    );
};