#ifndef SERVICES
#define SERVICES 

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace JSON 
{
    json* readFile(std::string path);
    void saveFile(std::string path, json* data);
}

#endif 
