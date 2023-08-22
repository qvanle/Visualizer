function Trie.insert(root, str, index): 
    if(root == nil) then 
        root = Trie.new()
    end 
    node.numberOfWords++ 
    if(index == #str) then 
        node.isEndOfWord = true 
        return root 
    end
    key = str[index]
    root.children[key] = Trie.insert(
        root.children[key], 
        str, 
        index + 1
    )
    return node
end 
