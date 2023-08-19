function AVl.insert(Node node, key)
    if(node == nil) then 
        return node(key, nil, nil)
    end 
    if(key < node.value) then 
        node.lson = AVL.insert(node.lson, key)
    else 
        node.rson = AVL.insert(node.rson, key)
    end
    node.make_balance()
end
