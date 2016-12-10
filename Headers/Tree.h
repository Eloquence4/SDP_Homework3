#ifndef TreeDec
#define TreeDec

enum TREE_ERRORS
{
    SEARCH_NO_RESULT
};

enum TREE_ITERATOR_ERRORS
{
    POINTER_IS_NULL,
    SIBLING_IS_NULL,
    SUCCESSOR_IS_NULL,
    ITERATOR_IS_INVALID
};

template<typename VarType>
struct Node
{
    VarType Data;
    Node* Sibling;
    Node* Successor;

    Node(VarType _Data = VarType(), Node* _Sibling = nullptr, Node* _Successor = nullptr)
        : Data(_Data)
        , Sibling(_Sibling)
        , Successor(_Successor)
    {   };

    bool operator==(const Node& rhs) const
    {
        return Data == rhs.Data;
    }
};

template<typename VarType>
class Tree
{
public:

    ///////// G4

    Tree();
    ~Tree();
    Tree(const Tree& source);
    Tree& operator=(const Tree& rhs);

    ////////////

    VarType& search(const VarType& key);
    const VarType& search(const VarType& key) const;

    void add(const VarType& what);

    void remove(const VarType& key);

#include "../HPPs/TreeIterator.hpp"

    TreeIterator front();

private:

    void copy(const Node<VarType>& _top);
    void clear();

    Node<VarType>* top;
};

#include "../HPPs/Tree.hpp"

#endif // TreeDec
