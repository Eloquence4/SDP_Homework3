#ifndef NodeDef

#include "string.h"

struct Word
{
    string phrase;
    int points;

    Word(string _phrase = string(), int _points = 0)
        : phrase(_phrase)
        , points(_points)
    {	};
};

#endif // NodeDef
