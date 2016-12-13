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

    auto it = tree.front();

    while(file.good())
    {
        buffer.resize(BUFFER_MAX_SIZE);
        file >> buffer;
        buffer.shringToFit();

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
                            it.addSibling(Word(int(), buffer));
                            it.goToSibling();
                        }
                        else
                        {
                            tree.add(Word(int(), buffer));
                            it = tree.front();
                        }
                    }
                    else
                    {
                        it.addSuccessor(Word(int(), buffer));
                        it.goToSuccessor();
                    }
                }
                else if(err == SUCCESSOR_IS_NULL)
                {
                    it.addSuccessor(Word(int(), buffer));
                    it.goToSuccessor();
                }
            }
            first = false;
        }
    }
}





