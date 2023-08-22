function HashTable.init(values, hashKey):
    HashTable.HASH_KEY = hashKey
    for i = 1, #values do
        HashTable.insert(values[i])
    end
end

