#include <services.hpp>

bool SIUSTRING::isSeparator(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == ',');
}

std::vector<std::string> SIUSTRING::split(std::string s)
{
    std::vector<std::string> result;

    int i = 0;
    while (i < s.length()) 
    {
        while(i < s.length() && isSeparator(s[i])) i++;
        if (i >= s.length()) break;
        result.push_back("");
        while(i < s.length() && !isSeparator(s[i])) result.back() += s[i++];
    }

    return result;
}
