function HashTable.search(value)
    key = value % HashTable.HASH_KEY
    root = HashTable.table[key]
    while(root ~= nil) do
        if root.value == value then
            return return true
        end
        root = root.next
    end
    return false
end
