function Trie.search(root, std::string word, index)
    if(root == nil) then 
        return false
    end
    if(index == #word) then
        return root.endOfWords > 0
    end 
    key = word[index]
        return search(
        root.children[key], 
        word, 
        index+1
    )
end
