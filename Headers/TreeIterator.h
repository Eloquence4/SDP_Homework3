#ifndef TreeIteratorDec
#define TreeIteratorDec

class TreeIterator
{
public:
    
    friend class Tree;

    VarType& data();
    const VarType& data() const;

    void goToSibling();
    void goToSuccessor();

    bool leaf() const;

    void addSibling();
    void addSuccessor();

    void deleteCur();

private:

    TreeIterator(Node<VarType>* ptr);

    void deleteAll(Node<VarType>* node);

    Node<VarType>* ptr;

};

#include "../HPPs/TreeIterator.hpp"

#endif
