/**
 *  
 * Solution to homework task
 * Data Structures Course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Ilian Georgiev
 * @idnumber 45134
 * @task 1
 * @compiler VC
 *
 */
#include <iostream>
#include "../Headers/string.h"

/////////////// G4

string::string()
    : text(nullptr)
    , maxSize(0)
    , curSize(0)
{
}

string::~string()
{
    delStr();
}

string& string::operator=(const string& rhs)
{
    if(this != &rhs)
        copy(rhs.text, rhs.maxSize);
    return *this;
}

string::string(const string & source)
    : text(nullptr)
    , maxSize(0)
    , curSize(0)
{
    copy(source.text, source.maxSize);
}

/////////////// Public

string::string(const char* initText)
    : text(nullptr)
    , maxSize(0)
    , curSize(0)
{
    copy(initText, strlen(initText));
}

string::string(int, const string& source)
    : text(nullptr)
    , maxSize(0)
    , curSize(0)
{
    text = new char[source.curSize + 1];

    int i = source.curSize + 1;

    while(i--)
        text[i] = source.text[i];

    curSize = source.curSize;
    maxSize = source.curSize;

}

size_t string::size() const
{
    return curSize;
}

size_t string::length() const
{
    return curSize;
}

size_t string::max_size() const
{
    return maxSize;
}

void string::resize(size_t targetSize)
{
    if(targetSize == 0)
    {
        delete[] text;
        maxSize = 0;
        return;
    }

    char* newString = new char[targetSize+1];

    if(!empty())
        if(targetSize > maxSize)
            for(size_t i = 0; i <= curSize; i++)
                newString[i] = text[i];
        else
        {
            for(size_t i = 0; i < targetSize-1; i++)
                newString[i] = text[i];
            newString[targetSize-1] = '\0';
        }
    else
        newString[1] = '\0';

    maxSize = targetSize;
    delete[] text;
    text = newString;
}

void string::reserve(size_t howMuch)
{
    resize(maxSize + howMuch);
}

void string::shringToFit()
{
    resize(curSize + 1);
}

bool string::empty() const
{
    return maxSize == 0 || text[0] == '\0';
}

char& string::operator[](int index)
{
    return this->at(index);
}

char& string::operator[](size_t index)
{
    return this->at(index);
}

char string::operator[](int index) const
{
    return this->at(index);
}

char string::operator[](size_t index) const
{
    return this->at(index);
}

char& string::at(int index)
{
    if(index < 0)
        throw ILLEGAL_INDEX;

    return this->at((size_t) index);
}

char& string::at(size_t index)
{
    if(index >= curSize)
        throw ILLEGAL_INDEX;
    else
        return text[index];
}

char string::at(int index) const
{
    if(index < 0)
        throw ILLEGAL_INDEX;

    return this->at((size_t)index);
}

char string::at(size_t index) const
{
    if(index >= curSize)
        throw ILLEGAL_INDEX;
    else
        return text[index];
}

char& string::front()
{
    if(empty())
        throw STRING_IS_EMPTY;

    return text[0];
}

char& string::back()
{
    if(empty())
        throw STRING_IS_EMPTY;

    return text[curSize-1];
}

char string::front() const
{
    if(empty())
        throw STRING_IS_EMPTY;

    return text[0];
}

char string::back() const
{
    if(empty())
        throw STRING_IS_EMPTY;

    return text[curSize - 1];
}

string& string::operator+=(const string& rhs)
{
    size_t str1Len = curSize;
    curSize += rhs.curSize;

    if(maxSize <= curSize)
        reserve(rhs.maxSize);

    for(size_t i = str1Len; i <= curSize; i++)
        text[i] = rhs.text[i - str1Len];

    return *this;
}

string string::operator+(const string& rhs) const
{
    string newString(*this);

    newString += rhs;

    return newString;
}

void string::append(const string & rhs)
{
    (*this) += rhs;
}

string & string::operator+=(const char * rhs)
{
    size_t str1Len = curSize;
    size_t str2Len = strlen(rhs);
    curSize += str2Len;

    if(maxSize <= curSize)
        reserve(str2Len);

    for(size_t i = str1Len; i <= curSize; i++)
        text[i] = rhs[i - str1Len];

    return *this;
}

string string::operator+(const char * rhs) const
{
    string newStr(*this);

    newStr += rhs;

    return newStr;
}

void string::append(const char * rhs)
{
    (*this) += rhs;
}

string& string::operator+=(char rhs)
{
    if(curSize >= maxSize)
        reserve((size_t)25);

    text[curSize] = rhs;
    text[++curSize] = '\0';

    return *this;
}

string string::operator+(char rhs) const
{
    string newStr(*this);

    newStr += rhs;

    return newStr;
}

void string::append(char rhs)
{
    (*this) += rhs;
}

bool string::operator==(const string& rhs) const
{
    if(curSize != rhs.curSize)
        return false;

    int i = 0;

    while(toLower(text[i]) == toLower(rhs.text[i]))
    {
        if(text[i] == '\0')
            return true;
        i++;
    }
    return false;
}

bool string::operator!=(const string& rhs) const
{
    return !(*this == rhs);
}

string::operator const char*() const
{
    return text;
}

void string::clear()
{
    if(maxSize != 0)
        text[0] = '\0';
    curSize = 0;
}

void string::shrink()
{
    if(maxSize == curSize)
        return;

    if(curSize == 0)
    {
        maxSize = 0;
        delete[] text;
    }

    char* newText = new char[curSize];

    for(size_t i = 0; i <= curSize; i++)
        newText[i] = text[i];

    delete[] text;
    text = newText;

    maxSize = curSize;
}

void string::assign(string& source)
{
    delete[] text;
    maxSize = source.maxSize;
    curSize = source.maxSize;
    text = source.text;

    source.text = nullptr;
    source.maxSize = 0;
    source.curSize = 0;
}

std::istream& operator>>(std::istream& lhs, string& rhs)
{
    lhs >> rhs.text;
    rhs.curSize = strlen(rhs.text);
    return lhs;
}

/////////////// Private

void string::delStr()
{
    curSize = 0;
    maxSize = 0;
    delete[] text;
}

void string::copy(const char* newText, size_t newMaxSize)
{
    char* tmpStr = new char[newMaxSize+1];

    int i;

    for(i = 0; newText[i] != '\0'; i++)
        tmpStr[i] = newText[i];

    curSize = i;

    tmpStr[i] = '\0';
    maxSize = newMaxSize;

    delete[] text;
    text = tmpStr;
}

char toLower(char a)
{
    if(a >= 'a' && a <= 'z')
        return a;
    else if(a >= 'A' && a <= 'Z')
        return a - 'A' + 'a';
	else return a;
}
