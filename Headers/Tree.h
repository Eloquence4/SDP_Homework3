#ifndef TreeDec
#define TreeDec

enum TREE_ERRORS
{
    SEARCH_NO_RESULT,
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
    Tree(const Tree<VarType>& source);
    Tree<VarType>& operator=(const Tree<VarType>& rhs);

    ////////////

    void add(const VarType& what);   // O(1), Adds a sibling to the top, inserts it between top and its first sibling

#include "../HPPs/TreeIterator.hpp"

    TreeIterator front()
    {
        return TreeIterator(top);
    }

    // O(n), unstable, throws SEARCH_NO_RESULT
    TreeIterator search(const VarType& key)
    {
        return search(top, key);
    }
    // O(n), unstable, throws SEARCH_NO_RESULT
    const TreeIterator search(const VarType& key) const
    {
        return search(top, key);
    }

private:
    TreeIterator search(Node<VarType>* node, const VarType& key)
    {
        if(!node)
            throw SEARCH_NO_RESULT;

        if(node->Data == key)
        {
            return TreeIterator(top, node);
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

    const TreeIterator search(const Node<VarType>* node, const VarType& key) const
    {
        if(!node)
            throw SEARCH_NO_RESULT;

        if(node->Data == key)
        {
            return TreeIterator(top, node);
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

    void copy(const Node<VarType>* _top);                   // O(1), only copies the top
    void copy(const Node<VarType>* from, Node<VarType>* to);// O(n), copies successors and sibblings
    void clear();                       // O(n)
    void clear(Node<VarType>* node);    // O(n)

    Node<VarType>* top;
};

#include "../HPPs/Tree.hpp"

#endif // TreeDec
