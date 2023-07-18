#ifndef GLOBAL 
#define GLOBAL 

#include <string>
#include <random>

enum class WINDOW_STATUS 
{
    IS_OPEN,
    IS_CLOSED
};
enum class SHAPE 
{
    NONE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE,
    LINE, 
    POLYGON
};

namespace PATH 
{
    const std::string ASSETS_ = "assets/";   

    const std::string ATTRIBUTE_ = "atb/";
    namespace ATB 
    {
        const std::string CONTAINER_ = "atb/container/";
    }
}

#endif 
