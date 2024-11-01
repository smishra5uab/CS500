#ifndef mystring_h
#define mystring_h

#include <iostream>

class MyString {
public:
    // Constructor to initialize from a C++ string
    MyString(const char* str, size_t length);

    MyString(const MyString& other);
    
    // Destructor to free memory
    ~MyString();
    
    // Convert to C++ string
    const char* toString() const;

    // Return length of the string
    size_t length() const;

    // Return substring from start index, up to n characters
    MyString substr(size_t start, size_t n = std::string::npos) const;

    // Concatenate two MyString objects
    MyString operator+(const MyString& other) const;

    // Append character or string (CS500 requirement)
    MyString& operator+=(const MyString& other);

    // Output stream operator overload
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    // Indexing operator overload
    const char& operator[](size_t index) const;

    // Relational operators
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

private:
    char* data;
    size_t len;

    void throwIfIndexOutOfBounds(size_t index) const;
};

#endif
