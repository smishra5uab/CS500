/*
 * File: main.cpp
 * This program plays the hangman game. From a list of words, a word is chosen at random. The player
 * is then given 8 attempts to guess the word letter by letter. Each time they make an incorrect
 * guess, one attempt is lost. The game completes either when the player guesses the entire word or
 * when they run out of attempts.
 */
#include <iostream>
#include <vector>
#include <string>
#include "randword.h"

// Function prototypes
void PrintWord(const std::string& word, const std::vector<bool>& guessed);
bool IsCorrect(char guess, const std::string& word);
bool UpdateWord(char guess, const std::string& word, std::vector<bool>& guessed);
bool IsComplete(const std::vector<bool>& guessed);

// Main program
int main() {

    // Initialize the dictionary from the file
    std::vector<std::string> dictionary = InitDictionary();
    if (dictionary.empty()) {
        std::cout << "Dictionary is empty. Exiting." << std::endl;
        return 1;
    }

    // Choose a random word from the dictionary
    std::string word = ChooseRandomWord(dictionary);
    std::vector<bool> guessed(word.length(), false);

    // set max attempts user can make
    int maxAttempts = 8;
    int incorrectGuesses = 0;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (incorrectGuesses < maxAttempts) {
        // Display the current state of the word on each iteration
        PrintWord(word, guessed);

        // Get user input
        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        // Validate input
        if (!isalpha(guess)) {
            std::cout << "Enter a valid letter." << std::endl;
            continue;
        }

        // Check if the guess is correct
        if (!IsCorrect(guess, word)) {
            if (!UpdateWord(guess, word, guessed)) {
                std::cout << "You've already guessed that letter!" << std::endl;
            }
        } else {
            incorrectGuesses++;
            std::cout << "Incorrect guess. You have " << (maxAttempts - incorrectGuesses) 
                << " guesses left." << std::endl;
        }

        // Check if the word is complete
        if (IsComplete(guessed)) {
            std::cout << "Yayy! You've guessed the word: " << word << std::endl;
            return 0;
        }
    }

    std::cout << "Oops!! Max attempts made. The word was: " << word << std::endl;
    return 0;
}

/* Function: PrintWord
 * Usage: PrintWord(word, guessed)
 * -------------------------------
 * This function shall print the word with dashes for letters that have not been guessed or guessed
 * incorrectly and fill in the letters that have been guessed correctly.
 */
void PrintWord(const std::string& word, const std::vector<bool>& guessed) {
    for (int i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            std::cout << word[i] << ' ';
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

/*
 * Function: IsCorrect
 * Usage: IsCorrect(guess, word)
 * ------------------------------
 * This function checks if the guessed character belongs in the word. Returns true if the character
 * is found.
 */
bool IsCorrect(char guess, const std::string& word) {
    for (char c : word) {
        if (c == guess) {
            return true;
        }
    }
    return false;
}

/*
 * Function: UpdateWord
 * Usage: UpdateWord(guess, word, guessed)
 * ----------------------------------------
 * This function checks and updates the guessed word. If a guess is correct and matches position
 * in the word, then the specific position in the guessedWord is set to true, hence updating the
 * word to show letters that are guessed correctly.
 */
bool UpdateWord(char guess, const std::string& word, std::vector<bool>& guessed) {
    bool correctGuess = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            guessed[i] = true;
            correctGuess = true;
        }
    }
    return correctGuess;
}

/*
 * Function: IsComplete
 * Usage: IsComplete(guessed)
 * ---------------------------
 * This function shall check if the word is guessed to completion. If true, the game is completed.
 */
bool IsComplete(const std::vector<bool>& guessed) {
    for (bool letterGuessed : guessed) {
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}
