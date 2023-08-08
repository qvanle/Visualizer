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

enum class BUTTON_STATUS 
{
    NONE,
    HOVER,
    RELEASED,
    CLICKED
};

enum class BUTTON_ACTION 
{
    CHANGE_SCREEN,
    INSERT,
    DELETE,
    INIT,
    SEARCH,
    SETTING,
    DONE,
    RANDOM,
    NONE, 
};

enum class DATA_STRUCTURES_TYPE 
{
    NONE,
    AVL, 
    HASH_TABLE,
    GRAPH, 
    TRIE,
    HEAP,
    BTREE_4TH
};
enum class HORIZONTAL_ALIGN
{
    LEFT,
    CENTER,
    RIGHT
};
enum class VERTICAL_ALIGN
{
    TOP,
    CENTER,
    BOTTOM
};

namespace DISPLAY 
{
    const std::string HOME_ = "home";
    const std::string WORKING_ = "working";
}

namespace PATH 
{
    const std::string ASSETS_ = "assets/";   
    namespace ASSETS 
    {
        const std::string GRAPHICS_ = "assets/graphics/";
        const std::string FONTS_ = "assets/fonts/";
    }
    const std::string ATTRIBUTE_ = "atb/";
    namespace ATB 
    {
        const std::string SPRITE_ = "atb/sprite/";
        const std::string OBJECT_ = "atb/object/";
        const std::string DISPLAY_ = "atb/display/";
        const std::string BUTTON_ = "atb/button/";
        const std::string DATA_STRUCTURES_ = "atb/data_structures/";
        const std::string INPUTBOX_ = "atb/input/";
    }
}

#endif 
