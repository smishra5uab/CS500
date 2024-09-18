/* 
 * File: randword.h
 * ----------------
 * This file defines the functions that shall be used to develop the hangman game.
 */
#ifndef _randword_h
#define _randword_h

#include <string>
#include <vector>

/*
 * Function: InitDictionary
 * Usage: InitDictionary(filename);
 * ---------------------------------
 * This function shall initialize the dictionary from the file being passed to it through the
 * implementation. If no words are found in the file, it shall print an error stating no words 
 * were found in the file.
 */
std::vector<std::string> InitDictionary();

/*
 * Function: ChooseRandomWord
 * Usage: ChooseRandomWord(dictionary);
 * ------------------------------------
 * This function shall serve to choose a random word from the passed dictionary.
 */
std::string ChooseRandomWord(const std::vector<std::string>& dictionary);

#endif