#ifndef FunctionsDec
#define FunctionsDec

#include <fstream>
#include "Tree.h"
#include "Word.h"

enum ERRORS
{
    INVALID_DICTIONARY_FORMAT
};

const int BUFFER_MAX_SIZE = 1048576; // 1 MB

bool checkIfNumber(const char* str);
bool checkIfLetter(char a);

double charToNum(char a);
double strToNum(const char* str);

void loadDictionary(Tree<Word>& tree, std::fstream& file);

#endif // FunctionsDec
