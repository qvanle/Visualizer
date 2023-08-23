function heap.top()
    if(#heap.heap == 0) then
        return nil
    end
    return heap.heap[0]
end
