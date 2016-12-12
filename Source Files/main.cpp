#include <iostream>
#include "../Headers/Word.h"
#include "../Headers/Tree.h"

int main(int argc, char* argv[])
{
    Tree<int> a;
    a.add(5);
    auto it = a.front();

    std::cout << it.data() << '\n';

    return 0;
}
