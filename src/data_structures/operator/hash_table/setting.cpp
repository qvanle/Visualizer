#include <data_structures.hpp>
#include <services.hpp>


void DataStructures::settingHashTable(InputBox* inp)
{
    std::vector<int> v = NUMBER::stringToArray(inp->getText(1));
    for(auto i : v) std::cout << i << " ";
    std::cout << "\n";
}


