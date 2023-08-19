function AVL.search(Node node, key)
    
    if(node == nil) then 
        return false 
    end 
    
    if(node.key == key) then 
        return true 
    end

    if(key < node.key) then 
        return AVL.search(node.left, key)
    else 
        return AVL.search(node.right, key)
    end

end
