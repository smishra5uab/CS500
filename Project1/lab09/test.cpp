#include <gtest/gtest.h>
#include "myString.h"

class MyStringTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup if needed
    }
    
    void TearDown() override {
        // Any cleanup if needed
    }
};

// Test the constructor
TEST_F(MyStringTest, Constructor_ValidInput) {
    MyString str("Hello", 5);
    EXPECT_EQ(str.length(), 5);
    EXPECT_STREQ(str.toString(), "Hello");
}

TEST_F(MyStringTest, Constructor_EmptyInput) {
    MyString str("", 0);
    EXPECT_EQ(str.length(), 0);
    EXPECT_STREQ(str.toString(), "");
}

// Test the destructor
TEST_F(MyStringTest, Destructor_CleansUpMemory) {
    MyString* str = new MyString("Hello", 5);
    delete str; // Test if no memory leak occurs
    // No specific assertion, just ensuring no crash
}

// Test the toString method
TEST_F(MyStringTest, ToString_ReturnsCorrectString) {
    MyString str("Test", 4);
    EXPECT_STREQ(str.toString(), "Test");
}

// Test the length method
TEST_F(MyStringTest, Length_ReturnsCorrectLength) {
    MyString str("Test", 4);
    EXPECT_EQ(str.length(), 4);
}

TEST_F(MyStringTest, Length_EmptyString) {
    MyString str("", 0);
    EXPECT_EQ(str.length(), 0);
}

// Test the substr method
TEST_F(MyStringTest, Substr_ValidSubstring) {
    MyString str("Hello, World!", 13);
    MyString sub = str.substr(7, 5);
    EXPECT_STREQ(sub.toString(), "World");
}

TEST_F(MyStringTest, Substr_OutOfBounds) {
    MyString str("Hello", 5);
    MyString sub = str.substr(1, 10); // Should return "ello"
    EXPECT_STREQ(sub.toString(), "ello");
}

// Test the concatenation operator
TEST_F(MyStringTest, OperatorPlus_ValidConcatenation) {
    MyString str1("Hello", 5);
    MyString str2(" World", 6);
    MyString result = str1 + str2;
    EXPECT_STREQ(result.toString(), "Hello World");
}

// Test the append operator
TEST_F(MyStringTest, OperatorPlusEquals_ValidAppend) {
    MyString str("Hello", 5);
    str += MyString(" World", 6);
    EXPECT_STREQ(str.toString(), "Hello World");
}

// Test the output stream operator
TEST_F(MyStringTest, OutputStreamOperator) {
    MyString str("Output Test", 11);
    std::ostringstream os;
    os << str;
    EXPECT_EQ(os.str(), "Output Test");
}

// Test the indexing operator
TEST_F(MyStringTest, IndexingOperator_ValidIndex) {
    MyString str("Hello", 5);
    EXPECT_EQ(str[1], 'e');
}

TEST_F(MyStringTest, IndexingOperator_OutOfBounds) {
    MyString str("Hello", 5);
    EXPECT_THROW(str[10], std::out_of_range); // Assuming you implement throwIfIndexOutOfBounds
}

// Test the relational operators
TEST_F(MyStringTest, OperatorEquals) {
    MyString str1("Hello", 5);
    MyString str2("Hello", 5);
    EXPECT_TRUE(str1 == str2);
}

TEST_F(MyStringTest, OperatorNotEquals) {
    MyString str1("Hello", 5);
    MyString str2("World", 5);
    EXPECT_TRUE(str1 != str2);
}

TEST_F(MyStringTest, OperatorLessThan) {
    MyString str1("Apple", 5);
    MyString str2("Banana", 6);
    EXPECT_TRUE(str1 < str2);
}

TEST_F(MyStringTest, OperatorGreaterThan) {
    MyString str1("Banana", 6);
    MyString str2("Apple", 5);
    EXPECT_TRUE(str1 > str2);
}

// Test edge cases for relational operators
TEST_F(MyStringTest, OperatorLessThanOrEqual) {
    MyString str1("A", 1);
    MyString str2("A", 1);
    EXPECT_TRUE(str1 <= str2);
}

TEST_F(MyStringTest, OperatorGreaterThanOrEqual) {
    MyString str1("Z", 1);
    MyString str2("Z", 1);
    EXPECT_TRUE(str1 >= str2);
}

// Test memory management and edge cases
TEST_F(MyStringTest, HandleMemoryManagement) {
    {
        MyString str1("Hello", 5);
        MyString str2 = str1; // Test copy constructor if implemented
        EXPECT_STREQ(str2.toString(), "Hello");
    } // Ensure destructor is called here

    // Check if double delete or memory leaks occur - usually done with tools like Valgrind
}
