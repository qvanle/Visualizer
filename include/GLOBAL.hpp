#ifndef GLOBAL 
#define GLOBAL 

#include <string>
#include <random>
#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

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
    namespace ASSETS 
    {
        const std::string GRAPHICS_ = "assets/graphics/";
    }
    const std::string ATTRIBUTE_ = "atb/";
    namespace ATB 
    {
        const std::string CONTAINER_ = "atb/container/";
    }
}

#endif 
