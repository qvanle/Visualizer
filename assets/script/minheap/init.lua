function minHeap.init(values)
    for i = 1, #values do
        minHeap.insert(values[i])
    end
end
