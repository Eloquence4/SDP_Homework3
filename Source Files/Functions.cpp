#include "../Headers/Functions.h"

bool checkIfNumber(const char* str)
{
    if(*str == '-')
        str++;
    if(*str == '\0')
        return false;

    do
    {
        if(*str < '0' && *str > '9')
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

double strToNum(char* str)
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
    char buffer[BUFFER_MAX_SIZE];
    char a;
    file.getline(buffer, std::numeric_limits<std::streamsize>::max());
}





