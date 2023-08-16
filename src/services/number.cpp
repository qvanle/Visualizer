#include <services.hpp>
#include <iostream>

std::string NUMBER::intToString(int64_t n)
{
    if(n == 0) return "0";
    std::string result = "";
    bool negative = false;
    if(n < 0)
    {
        negative = true;
        n *= -1;
    }

    while(n)
    {
        result = (char) (n % 10 + '0') + result;
        n /= 10;
    }

    return result;
}

std::vector<int> NUMBER::stringToArray(std::string s)
{
    std::vector<int> result;
    int i = 0;

    while(i != (int) s.size())
    {
        while(i != (int) s.size() && !NUMBER::isDigit(s[i])) i++;
        if(i == (int) s.size()) break;
        
        int n = 0;
        while(i != (int) s.size() && NUMBER::isDigit(s[i])) n = n * 10 + s[i++] - '0';
        result.push_back(n);
    }
    return result;
}

int64_t NUMBER::stringToInt(std::string s) 
{
    if(!NUMBER::isNumber(s)) return NUMBER::INF;
    if((int) s.size() > 18) return NUMBER::INF;
    if((int) s.size() == 1) return (int64_t) (s[0] - '0');

    int64_t n = 0;
    bool negative = false;
    bool sign = false;
    if(NUMBER::isSign(s[0]))
    {
        sign = true;
        negative = (s[0] == '-');
    }

    for(int i = sign; i < (int) s.size(); i++)
    {
        n *= 10;
        n += (int64_t) (s[i] - '0');
    }

    if(negative) n *= -1;

    return n;
}

bool NUMBER::isDigit(char c)
{
    if((int) c < 48 || (int) c > 57) return false;
    return true;
}

bool NUMBER::isLetter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
bool NUMBER::isSymbol(char c)
{
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '"' || c == '\'');
}

bool NUMBER::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool NUMBER::isSign(char c)
{
    return (c == '+' || c == '-');
}

bool NUMBER::isNumber(std::string s)
{
    if ((int) s.size() == 0)
        return false;
    if((int) s.size() == 1) 
        return isDigit(s[0]);
    if(!NUMBER::isSign(s[0]) && !NUMBER::isDigit(s[0]))
        return false;

    for (int i = 1; i < (int) s.size(); i++)
        if (!NUMBER::isDigit(s[i])) return false;

    return true;
}

bool NUMBER::isInInterval(std::string s, int64_t a, int64_t b)
{
    if (!NUMBER::isNumber(s)) return false;

    int64_t n = stringToInt(s);

    return (n >= a && n <= b);
}

std::string removeLeadingZero(std::string s)
{
    if(!NUMBER::isNumber(s)) return "0";

    bool isNegative = (s[0] == '-');
    bool isSign = NUMBER::isSign(s[0]);

    int i = isSign;
    while(s[i] == '0') i++;

    if(i == (int) s.size()) return "0";
    
    std::string result = "";
    if(isNegative) result += '-';
    for(; i < (int) s.size(); i++) result += s[i];

    return result;
}

