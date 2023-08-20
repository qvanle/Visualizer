#include <data_structures/graph.hpp>
#include <algorithm>
#include <queue>


void Graph::Dijkstra(int start)
{
    distance.clear();
    distance.resize(numberOfVertices + 1, -1);

    Dijkstra(adjList, start);
}

void Graph::Dijkstra(std::vector<EdgesList> & list, int u)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, u));
    distance[u] = 0;

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        for (auto & edge : list[v])
        {
            int w = edge.u;
            int weight = edge.weight;

            if (distance[w] == -1 || distance[w] > distance[v] + weight)
            {
                distance[w] = distance[v] + weight;
                pq.push(std::make_pair(distance[w], w));
            }
        }
    }
}
