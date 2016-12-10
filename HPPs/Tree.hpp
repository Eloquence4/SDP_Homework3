#ifndef TreeDef
#define TreeDef

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




template<typename VarType>
inline void Tree<VarType>::add(const VarType & what)
{
    Node<VarType>* newNode = new Node<VarType>(what, top->Sibling, nullptr);
    ptr->Sibling = newNode;
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
