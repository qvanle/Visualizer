#include <data_structures.hpp>

void DataStructures::dijkstra(InputBox* inp)
{
    int src = NUMBER::stringToInt(inp->getText(1));
    int dst = NUMBER::stringToInt(inp->getText(2));
    graph->Dijkstra(src, dst);
}
