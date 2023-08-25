#ifndef GLOBAL 
#define GLOBAL 

#include <string>
#include <random>
#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
/**
 * @brief Status of window
 */
enum class WINDOW_STATUS 
{
    IS_OPEN,
    IS_CLOSED
};
/**
 * @brief Kind of simple shape
 */
enum class SHAPE 
{
    NONE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE,
    LINE, 
    POLYGON
};
/**
 * @brief Status of button
 */
enum class BUTTON_STATUS 
{
    NONE,
    HOVER,
    RELEASED,
    CLICKED
};
/**
 * @brief Type of button
 */
enum class BUTTON_ACTION 
{
    CHANGE_SCREEN,
    INSERT,
    DELETE,
    INIT,
    SEARCH,
    SETTING,
    DONE,
    EDGES,
    GO_BACK,
    GO_NEXT,
    GO_ON,
    GO_OFF,
    SPEED_UP,
    SLOW_DOWN,
    CLOSE,
    TOP,
    SIZE,
    CONNECTED_COMPONENTS,
    MST,
    DIJKSTRA,
    RANDOM,
    RANDOM2,
    RANDOM3,
    RANDOM4,
    RANDOM5,
    RANDOM6,
    RANDOM7,
    RANDOM8,
    RANDOM9,
    RANDOM10,
    RANDOM11,
    RANDOM12,
    RANDOM13,
    RANDOM14,
    RANDOM15,
    RANDOM16,
    FILE,
    NONE, 
};
/**
 * @brief Type of data structures
 */
enum class DATA_STRUCTURES_TYPE 
{
    NONE,
    AVL, 
    HASH_TABLE,
    GRAPH, 
    TRIE,
    MIN_HEAP,
    MAX_HEAP,
    BTREE_4TH
};

/**
 * @brief Type of data structures operator
 */
enum class DATA_STRUCTURES_OPERATOR 
{
    INIT,
    INSERT,
    DELETE,
    SEARCH,
    TOP,
    SIZE,
    SCC,
    MST,
    DIJKSTRA,
    SETTING
};
/**
 * @brief Align in horizon axis
 */
enum class HORIZONTAL_ALIGN
{
    LEFT,
    CENTER,
    RIGHT
};
/**
 * @brief Align in vertical axis
 */
enum class VERTICAL_ALIGN
{
    TOP,
    CENTER,
    BOTTOM
};

/**
 * @brief Type of input
 */
enum class INPUT_TYPE
{
    NONE,
    INT,
    ARRAY,
    STRING,
    STRINGS
};

/**
 * @brief Name of display
 */
namespace DISPLAY 
{
    const std::string HOME_ = "home";
    const std::string WORKING_ = "working";
}

/**
 * @brief Path to assets, atributes, and saving files
 */
namespace PATH 
{
    const std::string ASSETS_ = "assets/";   
    namespace ASSETS 
    {
        const std::string GRAPHICS_ = "assets/graphics/";
        const std::string FONTS_ = "assets/fonts/";
        const std::string SCRIPT_ = "assets/script/";
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
        const std::string SCRIPT_ = "atb/script/";
    }

    const std::string SAVING_ = "saving/";
    namespace SAVING 
    {
        const std::string AVL_ = "saving/AVL.txt";
        const std::string HASH_TABLE_ = "saving/HASH_TABLE.txt";
        const std::string GRAPH_ = "saving/GRAPH.txt";
        const std::string TRIE_ = "saving/TRIE.txt";
        const std::string MIN_HEAP_ = "saving/MIN_HEAP.txt";
        const std::string MAX_HEAP_ = "saving/MAX_HEAP.txt";
        const std::string BTREE_4TH_ = "saving/BTREE_4TH.txt";
    }
}

#endif 
