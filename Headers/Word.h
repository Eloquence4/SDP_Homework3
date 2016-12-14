#ifndef WordDef
#define WordDef

#include "string.h"

struct Word
{
    string phrase;
    double points;

    Word(const string& _phrase = string(), double _points = 0)
        : phrase(int(), _phrase)
        , points(_points)
    {	};

    bool operator==(const Word& rhs) const
    {
        return phrase == rhs.phrase;
    }
};

#endif // NodeDef
