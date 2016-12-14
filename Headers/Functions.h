#ifndef FunctionsDec
#define FunctionsDec

#include <fstream>
#include "Tree.h"
#include "Word.h"

enum ERRORS
{
    INVALID_DICTIONARY_FORMAT,
    RECURSION_END,
    END_OF_FILE
};

const int BUFFER_MAX_SIZE = 1048576; // 1 MB

bool checkIfNumber(const char* str);
bool checkIfLetter(char a);

double charToNum(char a);
double strToNum(const char* str);

void loadDictionary(Tree<Word>& tree, std::fstream& file); // Unstable, throws INVALID_DICTIONARY_FORMAT

double evaluate(Tree<Word>& dictionary, std::fstream& file); 

double evaluate(Tree<Word>::TreeIterator& it, std::fstream& file, std::streampos& _index, int& words);

void getFirstWord(string& str, std::fstream& file);

#endif // FunctionsDec
