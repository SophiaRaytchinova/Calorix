#include "../include/core/Calorix.h"
#include <iostream>
#include <string>

int main() {
    Calorix system;
    system.load();
    std::cout << "--- Calorix Fitness System ---\nType 'help' for commands, 'end' to save and exit.\n";
    std::string line;
    while(true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin,line)) {
            break;
        }
        if (line == "end") {
            system.save(); 
            std::cout << "Saved. Goodbye.\n"; 
            break; 
        }
        system.executeCommand(line);
    }
    return 0;
}
