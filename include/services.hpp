#ifndef SERVICES
#define SERVICES 

#include <atomic>
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

namespace FILEE
{
    std::vector<std::string> readFile(std::string path);
}

namespace NUMBER 
{
    const int64_t INF = LLONG_MAX;
    int64_t stringToInt(std::string s);
    std::string intToString(int64_t n);
    bool isDigit(char c);
    bool isLetter(char c);
    bool isSymbol(char c);
    bool isSign(char c);
    bool isOperator(char c);
    std::string removeLeadingZero(std::string s);
    bool isNumber(std::string s);
    bool isInInterval(std::string s, int64_t a, int64_t b);
}

namespace RANDOM 
{
    extern std::mt19937 rng;
    int getInt(int a, int b);
    std::string getInt(int length, int a, int b);
    long long getLongLong(long long a, long long b);

    float getFloat(float a, float b);
    double getDouble(double a, double b);

    char getChar(char a, char b);
    char getChar();

    std::string getString(int length);
    std::string getString(int length, char a, char b);

    bool flipCoin();
}
namespace IMPLICIT_TREAP 
{
    template <typename T> class Node 
    {
        private:
            T NodeData;
            int priority;
            int treeSize;
            Node<T>* lson;
            Node<T>* rson;
        protected: 
            void updating();
            void lazyPushDown();
        public: 
            Node(T data);
            ~Node();

            T getData();
/**
            friend int size(Node<T>* node);
            friend void split(Node<T>* node, Node<T>*& lson, Node<T>*& rson, int sizeOfLeftTree);
            friend Node<T>* merge(Node<T>* lson, Node<T>* rson);
**/
    };
}
#endif 
