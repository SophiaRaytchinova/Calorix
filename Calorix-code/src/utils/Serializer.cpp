#include "../../include/utils/Serializer.h"
#include "../../include/core/Calorix.h"

void Serializer::save(const Calorix& system, const std::string&) 
{ 
    system.save(); 
}

void Serializer::load(Calorix& system, const std::string&)
{ 
    system.load(); 
}