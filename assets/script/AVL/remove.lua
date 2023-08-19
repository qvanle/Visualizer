function AVL.remove(Node node, key)
    
    if(node == nil) then 
        return nil 
    end 
    
    if(node.key == key) then 
        node = AVL.removeNode(node)
    else if(key < node.key) then 
        node.lson = AVL.remove(node.lson, key)
    else 
        node.rson = AVL.remove(node.rson, key)
    end

    node.make_balance()

    return node
end
