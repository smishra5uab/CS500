/*
 * File: randword.cpp
 * ------------------
 * This file is the implementation of randword.h interface.
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "randword.h"

/*
 * Implementation notes: InitDictionary
 * ------------------------------------
 * This function shall be used to initialize the dictionary to be used by hangman. The words file is
 * read word by word and each word is pushed into the dictionary.
 * The return of this function shall be the dictionary. If no file is found by the filename or the
 * file is empty, an error shall be printed.
 */
std::vector<std::string> InitDictionary() {
    std::vector<std::string> dictionary;
    std::string word;
    std::ifstream dictFile("words.txt");

    if (dictFile.is_open()) {
        while (dictFile >> word) {
            dictionary.push_back(word);
        }
        dictFile.close();
    } else {
        std::cout << "Could not open the dictionary file." << std::endl;
    }

    // Check if no words were found in the dictory and print relevant error
    if (dictionary.empty()) {
        std::cout << "No words found in the file." << std::endl;
    }

    return dictionary;
}

/*
 * Implementation notes: ChooseRandomWord
 * ---------------------------------------
 * This function shall return a random word that shall be used in the hangman game.
 * The passed dictionary must have atleast the size of 1 (contain atleast one word).
 * Seed with epoch time and then choose a random position from the dictionary to return.
 */
std::string ChooseRandomWord(const std::vector<std::string>& dictionary) {
    if (dictionary.empty()) {
        return "";
    }
    srand(time(0));
    int random = rand() % dictionary.size();
    return dictionary[random];
}