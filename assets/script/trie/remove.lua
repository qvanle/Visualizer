function Trie.remove(root, str, index)
    if(index == 0 and find(root, std, 0) == nil) then
        return root
    end
    if(index == #str) then 
        root.endOfWords-=1
    else
        key = str[index]
        root.children[key] = remove(
            root.children[key], 
            str, 
            index+1
        )
    end
    root = repair(root)
    return root
end 
