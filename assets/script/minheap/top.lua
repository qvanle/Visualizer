function minHeap.top()
    if(#minHeap.heap == 0) then
        return nil
    end
    return minHeap.heap[0]
end
