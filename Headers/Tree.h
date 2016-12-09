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
class TreeIterator;

template<typename VarType>
class Tree;

template<typename VarType>
class TreeIterator
{
public:

    TreeIterator(Tree& _source);

    void goToSibling();
    void goToSuccessor();

    bool leaf() const;

    void addSibling();
    void addSuccessor();

    void deleteCur();

private:

    void deleteAll(Node* node);

    Tree& source;
    Node* pos;

};

#include "../HPPs/TreeIterator.hpp"

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

    friend TreeIterator;

private:

    void copy(const Node& _top);
    void clear();

    Node* top;

};

#include "../HPPs/Tree.hpp"

#endif // TreeDec
