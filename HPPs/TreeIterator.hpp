#ifndef TreeIteratorDef
#define TreeIteratorDef

class TreeIterator
{
public:
    
    friend class Tree;

    VarType& data();            // O(1), unstable, throws POINTER_IS_NULL
    const VarType& data() const;// O(1), unstable, throws POINTER_IS_NULL

    void goToSibling();   // O(1), unstable, throws SIBLING_IS_NULL
    void goToSuccessor(); // O(1), unstable, throws SUCCESSOR_IS_NULL

    bool leaf() const;    // O(1)

    void addSibling(const VarType& data);  // O(1), Iterator stays in the same place, inserts the new
                                           // sibling between current node and its sibling to prevent O(n)
                                           // Unstable, throws POINTER_IS_NULL if iterator is empty
    void addSuccessor(const VarType& data);// O(1), Iterator stays in the same place, the new
                                           // successor becomes the first child to prevent O(n)
                                           // Unstable, throws POINTER_IS_NULL if iterator is empty

private:

    TreeIterator(Node<VarType>* _ptr); // O(1)

    void deleteAll(Node<VarType>* node); // O(n^2) Deletes every child and sibling to the given node

    Node<VarType>** first;
    Node<VarType>* ptr;
};

inline VarType& TreeIterator::data()
{
    return ptr->Data;
}

inline const VarType& TreeIterator::data() const
{
    if(ptr == nullptr)
        throw POINTER_IS_NULL;

    return ptr->Data;
}

inline void TreeIterator::goToSibling()
{
    if(ptr->Sibling == nullptr)
        throw SIBLING_IS_NULL;

    ptr = ptr->Sibling;
}

inline void TreeIterator::goToSuccessor()
{
    if(ptr->Successor == nullptr)
        throw SUCCESSOR_IS_NULL;

    ptr = ptr->Successor;
}

inline bool TreeIterator::leaf() const
{
    return ptr->Successor == nullptr;
}

inline void TreeIterator::addSibling(const VarType& data)
{
    if(ptr == nullptr)
        throw POINTER_IS_NULL;

    Node<VarType>* newNode = new Node<VarType>(data, ptr->Sibling);
    ptr->Sibling = newNode;
}

inline void TreeIterator::addSuccessor(const VarType & data)
{
    if(ptr == nullptr)
        throw POINTER_IS_NULL;

    Node<VarType>* newNode = new Node<VarType>(data, ptr->Successor);
    ptr->Successor = newNode;
}

inline TreeIterator::TreeIterator(Node<VarType>* _ptr)
    : first(&_ptr)
    , ptr(_ptr)
{ }

inline void TreeIterator::deleteAll(Node<VarType>* node)
{
    if(node == nullptr)
        return;

    deleteAll(node->Successor);
    deleteAll(node->Sibling);
    delete node;
}

#endif // TreeIteratorDef
