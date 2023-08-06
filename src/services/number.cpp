#include <services.hpp>

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
    return (c >= '0' && c <= '9');
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
