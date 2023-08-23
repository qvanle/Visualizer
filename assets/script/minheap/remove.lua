function heap.remove()
    if(#heap.heap == 0) then
        return 
    end
    swap(0, #heap.heap)
    heap.heap.pop_back()
    heap.heapify(0)
end
