function MST()  
    sortEdges()
    for(e in Edges) do 
        if(e.u is not connect e.v) then 
            connect(e.u, e.v)
        end
    end
end
