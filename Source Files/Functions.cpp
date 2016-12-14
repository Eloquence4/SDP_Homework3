#include "../Headers/Functions.h"

bool checkIfNumber(const char* str)
{
    bool point = false;

    if(*str == '-')
        str++;
    if(*str == '\0')
        return false;

    do
    {
        if(*str == '.')
            point = true;
        if(point && *str == '.')
            return false;
        if(*str < '0' || *str > '9')
            return false;
        
        ++str;

    } while(*str != '\0');

    return true;
}

bool checkIfLetter(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

double charToNum(char a)
{
    return a - '0';
}

double strToNum(const char* str)
{
    double res = 0;
    double multiplier = 1;
    bool positive = true;
    bool point = false;

    if(*str == '-')
    {
        positive = false;
        ++str;
    }

    while(*str != '\0')
    {
        if(*str == '.' && point == false)
        {
            point = true;
            ++str;
        }

        if(point == false)
            res = res * 10 + charToNum(*str);
        if(point == true)
        {
            double a = charToNum(*str);
            multiplier *= 10;
            a = a / multiplier;
            res = res + a;
        };
        ++str;
    }

    if(positive)
        return res;
    else
        return -res;
}

void loadDictionary(Tree<Word>& tree, std::fstream& file)
{
    string buffer;
    bool first = true;
    buffer.resize(BUFFER_MAX_SIZE);

    Tree<Word>::TreeIterator it = tree.front();

    while(file.good())
    {
        file >> buffer;

        if(first && checkIfNumber(buffer))
            throw INVALID_DICTIONARY_FORMAT;
        
        if(checkIfNumber(buffer))
        {
            it.data().points = strToNum(buffer);

            it = tree.front();
            first = true;
        }
        else
        {
            try
            {
                if(first)
                    it = it.searchSib(buffer);
                else
                {
                    it.goToSuccessor();
                    it = it.searchSib(buffer);
                }
            }
            catch(TREE_ERRORS& err)
            {
                if(err == SEARCH_NO_RESULT)
                {
                    if(first)
                    {
                        if(it.valid()) // It would only be invalid if the tree was just initialized and the iterator is null
                        {
                            it.addSibling(Word(buffer));
                            it.goToSibling();
                        }
                        else
                        {
                            tree.add(Word(buffer));
                            it = tree.front();
                        }
                    }
                    else
                    {
                        it.addSuccessor(Word(buffer));
                        it.goToSuccessor();
                    }
                }
                else if(err == SUCCESSOR_IS_NULL)
                {
                    it.addSuccessor(Word(buffer));
                    it.goToSuccessor();
                }
                else
                    throw err;
            }
            first = false;
        }
    }
}

double evaluate(Tree<Word>& dictionary, std::fstream& file)
{
    Tree<Word>::TreeIterator it = dictionary.front();

    double result = 0;

    std::streampos index = file.tellg();
    int wordCount = 0;

    try
    {
        while(true)
        {
            int words = 0;

            result += evaluate(it, file, index, words);

            wordCount += words;

            it = dictionary.front();
            file.seekg(index);
        }
    }
    catch(ERRORS& err)
    {
        if(err = RECURSION_END)
        {
            if(wordCount == 0)
                return 0;

            return result / wordCount;
        }
        else
            throw err;
    }
}

double evaluate(Tree<Word>::TreeIterator& it, std::fstream& file, std::streampos& _index, int& words)
{
    if(!file.good())
        throw RECURSION_END;

    string word;
    
    try
    {
        getFirstWord(word, file);
    }
    catch(ERRORS& err)
    {
        if(err = END_OF_FILE)
            throw RECURSION_END;
        else
            throw err;
    }

    std::streampos index = file.tellg();

    if(words != 0)
        it.goToSuccessor();

    try
    {
        it = it.searchSib(word);

        _index = index;
        words++;

        if(it.leaf())
            return it.data().points;
        else
            return it.data().points + evaluate(it, file, _index, words);

    }
    catch(TREE_ERRORS& err)
    {
        if(err == SEARCH_NO_RESULT)
        {
            if(words == 0)
            {
                words++;
                _index = index;
            }

            return 0;
        }
        else
            throw err;
    }

}

void getFirstWord(string& str, std::fstream& file)
{
    char g = file.get();

    while(!checkIfLetter(g))
    {
        if(!file.good())
            throw END_OF_FILE;
        g = file.get();
    }

    do
    {
        str += g;
        g = file.get();
    }
    while(checkIfLetter(g) && file.good());
}

