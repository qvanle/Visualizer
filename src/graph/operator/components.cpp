#include <data_structures/graph.hpp>
#include <stack>

void Graph::dfs(std::vector<EdgesList> &list, std::stack<int> &st, int u)
{
    static int counter = 0;
    order[u] = lowestOrder[u] = ++counter;
    st.push(u);

    for(auto & edge : list[u])
    {
        int v = edge.u;
        if(order[v] == 0)
        {
            dfs(list, st, v);
            lowestOrder[u] = std::min(lowestOrder[u], lowestOrder[v]);
        }
        else
        {
            lowestOrder[u] = std::min(lowestOrder[u], order[v]);
        }
    }

    if(lowestOrder[u] == order[u])
    {
        std::vector<int> component;
        while(true)
        {
            int v = st.top();
            st.pop();

            lowestOrder[v] = 2e9;
            order[v] = 2e9;

            component.push_back(v);
            if(v == u) break;
        }
        components.push_back(component);
    }
}

void Graph::splitConnected()
{
    order.resize(numberOfVertices + 1, 0);
    lowestOrder.resize(numberOfVertices + 1, 0);
    std::stack<int> st;
    for(int i = 0; i < numberOfVertices; i++)
    {
        if(order[i] == 0)
        {
            dfs(adjList, st, i);
        }
    }
}
