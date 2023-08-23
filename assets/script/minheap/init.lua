function heap.init(values)
    for i = 1, #values do
        heap.insert(values[i])
    end
end
