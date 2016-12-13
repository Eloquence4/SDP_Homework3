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
inline Tree<VarType>::Tree(const Tree<VarType>& source)
    : top(nullptr)
{
    copy(source.top);
}

template<typename VarType>
inline Tree<VarType>& Tree<VarType>::operator=(const Tree<VarType>& rhs)
{
    if(this != &rhs)
        copy(rhs.top);
    return *this;
}

/////////////////////////////////////////////////////////////// Public

template<typename VarType>
inline void Tree<VarType>::add(const VarType& what)
{
    if(top == nullptr)
        top = new Node<VarType>(what);
    else
        top->Sibling = new Node<VarType>(what, top->Sibling);
}

/////////////////////////////////////////////////////////////// Private

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
