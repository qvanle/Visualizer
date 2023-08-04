#ifndef SERVICES
#define SERVICES 

#include <string>
#include <math.h>
#include <climits>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace JSON 
{
    json* readFile(std::string path);
    void saveFile(std::string path, json* data);
}

namespace NUMBER 
{
    const int64_t INF = LLONG_MAX;
    int64_t stringToInt(std::string s);
    bool isDigit(char c);
    bool isSign(char c);
    bool isOperator(char c);
    std::string removeLeadingZero(std::string s);
    bool isNumber(std::string s);
    bool isInInterval(std::string s, int64_t a, int64_t b);
}

#endif 
