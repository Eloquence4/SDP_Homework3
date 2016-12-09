#ifndef TreeDec
#define TreeDec

enum TREE_ERRORS
{
    SEARCH_NO_RESULT
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

#include "TreeIterator.h"

    TreeIterator top();

private:

    void copy(const Node<VarType>& _top);
    void clear();

    Node<VarType>* top;
};

#include "../HPPs/Tree.hpp"

#endif // TreeDec
