#include <data_structures.hpp>

void DataStructures::initGraph(InputBox* inp)
{
    std::vector<std::vector<int> > g;

    g.resize(capacity);

    for(int i = 0; i < capacity; i++)
    {
        g[i].resize(capacity);
        for(int j = 0; j < capacity; j++)
        {
            g[i][j] = NUMBER::stringToInt(inp->getText(i * capacity + j + 1));
        }
    }

    graph->init(g);
}
