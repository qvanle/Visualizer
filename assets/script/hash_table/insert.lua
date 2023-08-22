function HashTable.insert(value)
    key = value % HashTable.HASH_KEY 
    root = HashTable.table[key]
    if(root == nil) then 
        root.value = value 
        return 
    end
    while(root.next ~= nil) do 
        root = root.next 
    end
    root.next.value = value
end
