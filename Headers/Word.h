#ifndef WordDef
#define WordDef

#include "string.h"

struct Word
{
    string phrase;
    double points;

    Word(string _phrase = string(), double _points = 0)
        : phrase(_phrase)
        , points(_points)
    {	};
};

#endif // NodeDef
