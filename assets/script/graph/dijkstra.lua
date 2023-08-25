function dijkstra(start, end):
    dist[i] = infinity for all i
    dist[start] = 0
    heap h

    h.insert(start)

    while h is not empty do
        u = h.SmallestDistance()
        h.pop()

        for (v in adj(u)) do 
            if dist[v] > dist[u] + weight(u, v) then
                dist[v] = dist[u] + weight(u, v)
                h.insert(v)
        end
    end
end
