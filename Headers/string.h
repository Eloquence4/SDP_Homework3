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
#ifndef StringDef
#define StringDef
#include <iostream>

enum STRING_ERRORS
{
    ILLEGAL_INDEX,
    STRING_IS_EMPTY
};

class string
{
public:
    ////////////// G4
    string();                             // O(1)
    ~string();                            // O(1)
    string& operator=(const string& rhs); // O(n), O(1) if this == &rhs
    string(const string& source);         // O(n)
    /////////////////

    string(const char* initText);      // O(n)
    string(int, const string& source); // O(n), copies the contents of the string only, without the empty space after

    size_t size() const;    // O(1), Returns max string length
    size_t length() const;  // O(1), Returns the string length
    size_t max_size() const;// O(1), Returns max string size before having to resize

    void resize(size_t targetSize); // O(n), Resizes the string
    void reserve(size_t howMuch);   // O(n), Resizes the string to the current size + howMuch
    void shringToFit();             // O(n), Resizes the string to fit the current size

    bool empty() const; // O(1), Check if empty

    char& operator[](int index);        // O(1), Unstable, throws ILLEGAL_INDEX
    char& operator[](size_t index);     // O(1), Unstable, throws ILLEGAL_INDEX
    char operator[](int index) const;   // O(1), Unstable, throws ILLEGAL_INDEX
    char operator[](size_t index) const;// O(1), Unstable, throws ILLEGAL_INDEX
    char& at(int index);                // O(1), Unstable, throws ILLEGAL_INDEX
    char& at(size_t index);             // O(1), Unstable, throws ILLEGAL_INDEX
    char at(int index) const;           // O(1), Unstable, throws ILLEGAL_INDEX
    char at(size_t index) const;        // O(1), Unstable, throws ILLEGAL_INDEX

    char& front();      // O(1), unstable, throws STRING_IS_EMPTY
    char& back();       // O(1), unstable, throws STRING_IS_EMPTY
    char front() const; // O(1), unstable, throws STRING_IS_EMPTY
    char back() const;  // O(1), unstable, throws STRING_IS_EMPTY

    string& operator+=(const string& rhs);      // O(n) or O(2n) if no additional space is reserved
    string operator+(const string& rhs) const;  // O(n) or O(2n) if no additional space is reserved
    void append(const string& rhs);             // O(1) or O(n) if no additional space is reserved

    string& operator+=(const char* rhs);        // O(n) or O(2n) if no additional space is reserved
    string operator+(const char* rhs) const;    // O(n) or O(2n) if no additional space is reserved
    void append(const char* rhs);               // O(1) or O(n) if no additional space is reserved

    string& operator+=(char rhs);       // O(1) or O(n) if no additional space is reserved
    string operator+(char rhs) const;   // O(1) or O(n) if no additional space is reserved
    void append(char rhs);              // O(1) or O(n) if no additional space is reserved

    // Warning, operator== is not case sensitive, so if we have "a" and "A" then it will return true
    bool operator==(const string& rhs) const; // O(n)
    bool operator!=(const string& rhs) const; // O(n)

    operator const char*() const; // O(1)

    void clear(); // O(1)
    void shrink();// O(n)

    void assign(string& source); // O(1), this becomes source, source becomes empty

    friend std::istream& operator>>(std::istream& lhs, string& rhs);

private:

    void delStr(); // O(1)
    void copy(const char* newText, size_t newMaxSize); // O(n)

    char* text;
    size_t maxSize;
    size_t curSize;
};

char toLower(char a);

#endif // StringDef


