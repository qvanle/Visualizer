function HashTable.remove(value)
    key = value % HashTable.HASH_KEY
    root = HashTable.table[key]
    if root == nil then
        return
    end
    if root.value == value then
        HashTable.table[key] = root.next
        return
    end
    while root.next ~= nil do
        if root.next.value == value then
            root.next = root.next.next
            break
        end
        root = root.next
    end
end
