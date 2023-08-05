#ifndef SERVICES
#define SERVICES 

#include <string>
#include <math.h>
#include <climits>
#include <random>
#include <chrono>

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

namespace RANDOM 
{
    const std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int getInt(int a, int b);
    long long getLongLong(long long a, long long b);
    
    float getFloat(float a, float b);
    double getDouble(double a, double b);
    
    char getChar(char a, char b);
    char getChar();
    
    std::string getString(int length);
    std::string getString(int length, char a, char b);

    bool flipCoin();
}

#endif 
