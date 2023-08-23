function heap.insert(value)
    table.insert(heap.values, value)

    local index = #heap.values
    
    if(index == 0) then 
        return 
    end

    while(index != 0) do 
        local parent = (index - 1) / 2;
        if(heap.swapable(parent, index)) then 
            heap.swap(parent, index)
        end
        index = parent
    end
end
