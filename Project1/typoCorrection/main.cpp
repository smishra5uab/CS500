/*
 * File:main.cpp
 * This program shall be used to fix a common typing mistake of pressing the key to the right
 * of intended key. It uses 
 */
#include <iostream>
#include <string>
#include <map>

// Main program
int main() {
    // map keyToLeft is used to map each key input with the input to its left.
    std::map<char, char> keyToLeft;
    keyToLeft['W'] = 'Q'; keyToLeft['E'] = 'W'; keyToLeft['R'] = 'E'; keyToLeft['T'] = 'R'; keyToLeft['Y'] = 'T'; keyToLeft['U'] = 'Y'; keyToLeft['I'] = 'U'; keyToLeft['O'] = 'I'; keyToLeft['P'] = 'O';
    keyToLeft['S'] = 'A'; keyToLeft['D'] = 'S'; keyToLeft['F'] = 'D'; keyToLeft['G'] = 'F'; keyToLeft['H'] = 'G'; keyToLeft['J'] = 'H'; keyToLeft['K'] = 'J'; keyToLeft['L'] = 'K'; keyToLeft[';'] = 'L';
    keyToLeft['X'] = 'Z'; keyToLeft['C'] = 'X'; keyToLeft['V'] = 'C'; keyToLeft['B'] = 'V'; keyToLeft['N'] = 'B'; keyToLeft['M'] = 'N';
    keyToLeft[','] = 'M'; keyToLeft['.'] = ','; keyToLeft['/'] = '.';
    keyToLeft[' '] = ' '; // Space remains unchanged
    keyToLeft['1'] = '`'; keyToLeft['2'] = '1'; keyToLeft['3'] = '2'; keyToLeft['4'] = '3'; keyToLeft['5'] = '4'; keyToLeft['6'] = '5'; keyToLeft['7'] = '6'; keyToLeft['8'] = '7'; keyToLeft['9'] = '8'; keyToLeft['0'] = '9';
    keyToLeft['-'] = '0'; keyToLeft['='] = '-';

    // Read user input line by line
    std::string line;
    while (getline(std::cin, line)) {
        // User can enter the word EXIT to exit the execution whenever completed
        if (line == "EXIT") {
            break;
        }
        /*
         * Run a for loop that checks if the character in the line is found in the map and only
         * alter such characters.
         */
        for (int i = 0; i < line.size(); ++i) {
            if (keyToLeft.find(line[i]) != keyToLeft.end()) {
                line[i] = keyToLeft[line[i]];
            }
        }
        std::cout << line << std::endl;
    }

    return 0;
}
