#ifndef NodeDef

#include "string.h"

struct Node
{
    string phrase;
    int points;

    Node(string _phrase = string(), int _points = 0)
        : phrase(_phrase)
        , points(_points)
    {	};
};

#endif // NodeDef
