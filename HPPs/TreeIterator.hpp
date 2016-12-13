#ifndef TreeIteratorDef
#define TreeIteratorDef

class TreeIterator
{
    friend class Tree;

public:

    // O(1), unstable, throws POINTER_IS_NULL
    VarType& data()
    {
        return ptr->Data;
    }

    // O(n), searches for a successor, unstable, throws SEARCH_NO_RESULT
    // Requires operator== defined for VarType
    TreeIterator searchSucc(const VarType& key)
    {
        return searchSucc(ptr, key);
    }

    // O(n), searches for a sibling, unstable, throws SEARCH_NO_RESULT
    // Requires operator== defined for VarType
    TreeIterator searchSib(const VarType& key)
    {
        return searchSib(ptr, key);
    }

    // O(1), unstable, throws POINTER_IS_NULL
    const VarType& data() const
    {
        if(ptr == nullptr)
            throw POINTER_IS_NULL;

        return ptr->Data;
    }

    // O(1), unstable, throws SIBLING_IS_NULL
    void goToSibling()
    {
        if(ptr->Sibling == nullptr)
            throw SIBLING_IS_NULL;

        ptr = ptr->Sibling;
    }

    // O(1), unstable, throws SUCCESSOR_IS_NULL
    void goToSuccessor()
    {
        if(ptr->Successor == nullptr)
            throw SUCCESSOR_IS_NULL;

        ptr = ptr->Successor;
    }

    // O(1)
    bool leaf() const
    {
        return ptr->Successor == nullptr;
    }

    // O(1), Iterator stays in the same place, inserts the new
    // sibling between current node and its sibling to prevent O(n)
    void addSibling(const VarType& data)
    {
        if(ptr == nullptr)
            throw POINTER_IS_NULL;
        else
        {
            Node<VarType>* newNode = new Node<VarType>(data, ptr->Sibling);
            ptr->Sibling = newNode;
        }
    }

    // O(1), Iterator stays in the same place, the new
    // successor becomes the first child to prevent O(n)
    // Unstable, throws POINTER_IS_NULL if iterator is empty
    void addSuccessor(const VarType& data)
    {
        if(ptr == nullptr)
            throw POINTER_IS_NULL;

        Node<VarType>* newNode = new Node<VarType>(data, ptr->Successor);
        ptr->Successor = newNode;
    }

    // O(1), checks if the iterator is valid
    bool valid() const
    {
        return ptr != nullptr;
    }

private:
    // O(1)
    TreeIterator(Node<VarType>* _ptr)
        : first(&_ptr)
        , ptr(_ptr)
    { }
    // O(1)
    TreeIterator(Node<VarType>* _top, Node<VarType>* _node)
        : first(&_top)
        , ptr(_node)
    { }

    // O(n) Deletes every child and sibling to the given node
    void deleteAll(Node<VarType>* node)
    {
        if(node == nullptr)
        return;

        deleteAll(node->Successor);
        deleteAll(node->Sibling);
        delete node;
    }

    TreeIterator searchSucc(Node<VarType>* node, const VarType& key)
    {
        if(!node)
            throw SEARCH_NO_RESULT;

        if(key == node->Data)
            return TreeIterator(*first, node);
        else
            return searchSucc(node->Successor, key);
    }

    TreeIterator searchSib(Node<VarType>* node, const VarType& key)
    {
        if(!node)
            throw SEARCH_NO_RESULT;

        if(key == node->Data)
            return TreeIterator(*first, node);
        else
            return searchSib(node->Sibling, key);
    }

    Node<VarType>** first;
    Node<VarType>* ptr;
};

#endif // TreeIteratorDef
