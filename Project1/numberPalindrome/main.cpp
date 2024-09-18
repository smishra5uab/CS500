/*
 * File: main.cpp
 * This purpose of this program is to find palindrome numbers using the reverse and add method. The
 * program shall take an input of how many test cases shall be used and their values respectively.
 * Then it shall use a mixed implementation of string palindromes and reverse and add to find the
 * palindrome and also print how many attempts it took to reach there.
 */
#include <iostream>
#include <string>
#include <algorithm>

// Function prototypes
bool isPalindrome(int number);
int reverseNumber(int number);

// Main program
int main() {
    int testCases;
    std::cin >> testCases;

    /*
     * The while loop here shall function on each testCase; take the number; perform the check for
     * palindrome; allow next testCase if pass; reverse and add and repeat if not.
     * It shall print the number of iterations and the palindrome number.
     */
    while (testCases--) {
        int num;
        std::cin >> num;

        int iterations = 0;
        int current = num;

        while (!isPalindrome(current)) {
            int reversed = reverseNumber(current);
            current += reversed;
            iterations++;
        }

        std::cout << iterations << " " << current << std::endl;
    }

    return 0;
}

/*
 * Function: isPalindrome
 * Usage: isPalindrome(number)
 * ----------------------------
 * isPalindrome shall take the number, convert it to a string, reverse the string and check if the
 * string and it's reverse are same. Returns the value of comparison.
 */
bool isPalindrome(int number) {
    std::string str = std::to_string(number);
    std::string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}

/*
 * Function: reverseNumber
 * Usage: reverseNumber(number)
 * -----------------------------
 * reverseNumber takes the number and reverses it by converting it to string, then using reverse
 * function to reverse the string and then the stoi string function to convert the string to int.
 */
int reverseNumber(int number) {
    std::string str = std::to_string(number);
    reverse(str.begin(), str.end());
    return stoi(str);
}