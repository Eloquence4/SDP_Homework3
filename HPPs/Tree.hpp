#ifndef TreeDef
#define TreeDef

/////////////////////////////////////////////////////////////// G4

template<typename VarType>
inline Tree<VarType>::Tree()
    : top(nullptr)
{ }

template<typename VarType>
inline Tree<VarType>::~Tree()
{
    clear();
}

template<typename VarType>
inline Tree<VarType>::Tree(const Tree& source)
    : top(nullptr)
{
    copy(source.top);
}

template<typename VarType>
inline Tree& Tree<VarType>::operator=(const Tree& rhs)
{
    if(this == &rhs)
        return;
    copy(rhs.top);
}

/////////////////////////////////////////////////////////////// Public

template<typename VarType>
inline VarType& Tree<VarType>::search(const VarType& key)
{
    return search(top, key);
}

template<typename VarType>
inline const VarType & Tree<VarType>::search(const VarType & key) const
{
    return search(top, key);
}

template<typename VarType>
inline void Tree<VarType>::add(const VarType& what)
{
    Node<VarType>* newNode = new Node<VarType>(what, top->Sibling, nullptr);
    ptr->Sibling = newNode;
}

template<typename VarType>
inline void Tree<VarType>::remove(const VarType& key)
{
    if(!top)
        return;
    remove(top, key);
}

template<typename VarType>
inline TreeIterator Tree<VarType>::front()
{
    return TreeIterator(top);
}

/////////////////////////////////////////////////////////////// Private

template<typename VarType>
inline VarType& Tree<VarType>::search(const Node<VarType>* node, const VarType& key)
{
    if(!node)
        throw SEARCH_NO_RESULT;

    if(node->Data == key)
    {
        return node->Data;
    }
    else
    {
        try
        {
            return search(node->Successor, key);
        }
        catch(TREE_ERRORS& err)
        {
            if(err == SEARCH_NO_RESULT)
                return search(node->Sibling, key);
        }
    }
}

template<typename VarType>
inline const VarType& Tree<VarType>::search(const Node<VarType>* node, const VarType & key) const
{
    if(!node)
        throw SEARCH_NO_RESULT;

    if(node->Data == key)
    {
        return node->Data;
    }
    else
    {
        try
        {
            return search(node->Successor, key);
        }
        catch(TREE_ERRORS& err)
        {
            if(err == SEARCH_NO_RESULT)
                return search(node->Sibling, key);
        }
    }
}

template<typename VarType>
inline bool Tree<VarType>::remove(Node<VarType>* node, const VarType & key)
{
    
}

template<typename VarType>
inline void Tree<VarType>::copy(const Node<VarType>* _top)
{
    if(_top)
    {
        top = new Node<VarType>(_top->Data);
        copy(_top, top);
    }
}

template<typename VarType>
inline void Tree<VarType>::copy(const Node<VarType>* from, Node<VarType>* to)
{
    if(from->Successor)
    {
        to->Successor = new Node<VarType>(from->Successor->Data);
        copy(from->Successor, to->Successor);
    }
    if(from->Sibling)
    {
        to->Sibling = new Node<VarType>(from->Sibling->Data);
        copy(from->Sibling, to->Sibling);
    }
}

template<typename VarType>
inline void Tree<VarType>::clear()
{
    clear(top);
    top = nullptr;
}

template<typename VarType>
inline void Tree<VarType>::clear(Node<VarType>* node)
{
    if(node == nullptr)
        return;

    clear(node->Successor);
    clear(node->Sibling);
    delete node;
}

#endif // TreeDef
