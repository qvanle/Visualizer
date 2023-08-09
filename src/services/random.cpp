#include <services.hpp>

std::mt19937 RANDOM::rng = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());

int RANDOM::getInt(int a, int b)
{
    return std::uniform_int_distribution<int> (a, b)(rng);
}

std::string RANDOM::getInt(int length, int a, int b)
{
    if(length == 0) return "";
    std::string result = NUMBER::intToString(RANDOM::getInt(a, b));

    while(--length) result = result + " " + NUMBER::intToString(RANDOM::getInt(a, b));
    return result;
}

long long RANDOM::getLongLong(long long a, long long b)
{
    return std::uniform_int_distribution<long long> (a, b)(rng);
}

float RANDOM::getFloat(float a, float b)
{
    return std::uniform_real_distribution<float> (a, b)(rng);
}

double RANDOM::getDouble(double a, double b)
{
    return std::uniform_real_distribution<double> (a, b)(rng);
}

char RANDOM::getChar(char a, char b)
{
    return std::uniform_int_distribution<char> (a, b)(rng);
}

char RANDOM::getChar()
{
    return getChar('a', 'z');
}

std::string RANDOM::getString(int length)
{
    std::string s = "";
    for (int i = 0; i < length; i++)
        s += getChar();
    return s;
}

std::string RANDOM::getString(int length, char a, char b)
{
    std::string s = "";
    for (int i = 0; i < length; i++)
        s += getChar(a, b);
    return s;
}

bool RANDOM::flipCoin()
{
    return getInt(1, 2) - 1;
}
