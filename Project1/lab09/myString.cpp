#include "myString.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

/*
 * Constructor
 * =============
 * Firstly set the length to be the same as that of input string.
 * Allocate the memory and the null terminator of a typical string.
 * Copy the characters from str to data.
 * Add the null terminator in the end.
 */ 
MyString::MyString(const char* str, size_t length) {
    len = length;
    data = new char[len + 1];
    std::strncpy(data, str, len);
    data[len] = '\0';
}

MyString::MyString(const MyString& other) {
    len = other.len;
    data = new char[len + 1];
    std::strcpy(data, other.data);
}



// Destructor
MyString::~MyString() {
    delete[] data;
}

// Self explanatory
const char* MyString::toString() const {
    return data;
}

// Returns the length of the string
size_t MyString::length() const {
    return len;
}

// substr checks for the given start to be in bounds and then returns the correct substring
// whether or not n is passed
MyString MyString::substr(size_t start, size_t n) const {
    throwIfIndexOutOfBounds(start);
    size_t substr_len = (n == std::string::npos || start + n > len) ? len - start : n;
    return MyString(data + start, substr_len);
}


// Concatenate two MyString objects
MyString MyString::operator+(const MyString& otherString) const {
    char* newData = new char[len + otherString.len + 1];
    std::strcpy(newData, data);
    std::strcat(newData, otherString.data);
    MyString result(newData, len + otherString.len);
    delete[] newData;
    return result;
}

// Append MyString to existing string
MyString& MyString::operator+=(const MyString& otherString) {
    char* newData = new char[len + otherString.len + 1];
    std::strcpy(newData, data);
    std::strcat(newData, otherString.data);
    delete[] data;
    data = newData;
    len += otherString.len;
    return *this;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

// indexing operator overload
const char& MyString::operator[](size_t index) const {
    throwIfIndexOutOfBounds(index);
    return data[index];
}

// relational operators overload
bool MyString::operator==(const MyString& otherString) const {
    return std::strcmp(data, otherString.data) == 0;
}

bool MyString::operator!=(const MyString& otherString) const {
    return !(*this == otherString);
}

bool MyString::operator<(const MyString& otherString) const {
    return std::strcmp(data, otherString.data) < 0;
}

bool MyString::operator<=(const MyString& otherString) const {
    return std::strcmp(data, otherString.data) <= 0;
}

bool MyString::operator>(const MyString& otherString) const {
    return std::strcmp(data, otherString.data) > 0;
}

bool MyString::operator>=(const MyString& otherString) const {
    return std::strcmp(data, otherString.data) >= 0;
}

// Check and throw index out of bounds errors
void MyString::throwIfIndexOutOfBounds(size_t index) const {
    if (index >= len) {
        throw std::out_of_range("Index out of bounds");
    }
}
