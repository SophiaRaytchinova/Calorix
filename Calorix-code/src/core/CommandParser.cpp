#include "../../include/core/CommandParser.h"
#include <sstream>

std::vector<std::string> CommandParser::split(const std::string& commandLine)
{ 
    std::vector<std::string> tokens; 
    std::stringstream ss(commandLine); 
    std::string token; 
    while (ss >> token) 
    { 
        tokens.push_back(token); 
    } 
    return tokens; 
}
