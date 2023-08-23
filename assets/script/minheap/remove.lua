function minHeap.remove()
    if(#minHeap.heap == 0) then
        return 
    end
    swap(0, #minHeap.heap)
    minHeap.heap.pop_back()
    minHeap.heapify(0)
end
