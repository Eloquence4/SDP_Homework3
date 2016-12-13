#ifndef WordDef
#define WordDef

#include "string.h"

struct Word
{
    string phrase;
    double points;

    Word(const string& _phrase = string(), double _points = 0)
        : phrase(_phrase)
        , points(_points)
    {	};

    Word(int, string& _phrase, double _points = 0) // Assigns a string instead of copying it
        : points(_points)
    {
        phrase.assign(_phrase);
    }

    bool operator==(const Word& rhs) const
    {
        return phrase == rhs.phrase;
    }
};

#endif // NodeDef
