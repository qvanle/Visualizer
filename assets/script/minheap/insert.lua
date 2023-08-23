function minHeap.insert(value)
    table.insert(minHeap.heap, value)

    local index = #minHeap.heap
    
    if(index == 0) then 
        return 
    end

    while(index != 0) do 
        local parent = (index - 1) / 2;
        if(minHeap.swapable(parent, index)) then 
            minHeap.swap(parent, index)
        end
        index = parent
    end
end
