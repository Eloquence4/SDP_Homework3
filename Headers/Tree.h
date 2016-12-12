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

    VarType& search(const VarType& key);            // O(n), unstable, throws SEARCH_NO_RESULT
    const VarType& search(const VarType& key) const;// O(n), unstable, throws SEARCH_NO_RESULT

    void add(const VarType& what);   // O(1), Adds a sibling to the top, inserts it between top and its first sibling

#include "../HPPs/TreeIterator.hpp"

    TreeIterator front();

private:
    VarType& search(const Node<VarType>* node, const VarType& key);
    const VarType& search(const Node<VarType>* node, const VarType& key) const;

    bool remove(Node<VarType>* node, const VarType& key);

    void copy(const Node<VarType>* _top);                   // O(1), only copies the top
    void copy(const Node<VarType>* from, Node<VarType>* to);// O(n), copies successors and sibblings
    void clear();                       // O(n)
    void clear(Node<VarType>* node);    // O(n)

    Node<VarType>* top;
};

#include "../HPPs/Tree.hpp"

#endif // TreeDec
