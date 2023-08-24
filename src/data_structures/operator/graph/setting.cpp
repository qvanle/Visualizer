#include <data_structures.hpp>
#include <services.hpp>


void DataStructures::settingGraph(InputBox* inp)
{
    std::vector<int> v1 = NUMBER::stringToArray(inp->getText(1));
    std::vector<int> v2 = NUMBER::stringToArray(inp->getText(2));
    std::vector<int> v3 = NUMBER::stringToArray(inp->getText(3));
    std::vector<int> v4 = NUMBER::stringToArray(inp->getText(4));
    
    SDL_Color c1;
    c1.r = v1[0];
    c1.g = v1[1];
    c1.b = v1[2];
    if(v1.size() >= 4) c1.a = v1[3];
    else c1.a = 255;

    SDL_Color c2;
    c2.r = v2[0];
    c2.g = v2[1];
    c2.b = v2[2];
    if(v2.size() >= 4) c2.a = v2[3];
    else c2.a = 255;

    SDL_Color c3;
    c3.r = v3[0];
    c3.g = v3[1];
    c3.b = v3[2];
    if(v3.size() >= 4) c3.a = v3[3];
    else c3.a = 255;

    SDL_Color c4;
    c4.r = v4[0];
    c4.g = v4[1];
    c4.b = v4[2];
    if(v4.size() >= 4) c4.a = v4[3];
    else c4.a = 255;
    
    Object::coloring(c1);
    Object::fillWithColor();

    graph->setting(c1, c2, c3, c4);
}

