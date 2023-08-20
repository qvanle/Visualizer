#include <data_structures/graph.hpp>

void Graph::init(std::vector< std::vector<int> > matrix)
{
    numberOfVertices = matrix.size();

    for(int i = 0; i < numberOfVertices; i++)
    {
        EdgesList list;
        for(int j = 0; j < numberOfVertices; j++)
        {
            if(matrix[i][j] != 0)
            {
                list.push_back(Edges(i, j, matrix[i][j]));
                numberOfEdges++;
            }
        }
        adjList.push_back(list);
    }
}
