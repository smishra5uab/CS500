#ifndef HAMMINGCODE_H
#define HAMMINGCODE_H

#include "Eigen/Dense"
#include <string>
#include <vector>

/**
 * @class HammingCode
 * @brief Implements (7,4) Hamming Code operations, including encoding, decoding, and error correction.
 * This class provides methods for decoding Hamming (7,4) encoded code words,
 * correcting single-bit errors, and detecting multiple errors. It uses matrix
 * multiplication modulo 2 for error detection and correction.
 */

class HammingCode {
public:
    /**
     * @brief Constructor to initialize the generator and parity-check matrices.
     * This constructor initializes the generator and parity-check matrices that
     * are used for encoding and decoding Hamming code words.
     */
    HammingCode();

    /**
     * @brief Decodes Hamming (7,4) code words from a file and corrects errors if possible.
     * Reads a file containing encoded Hamming (7,4) code words, decodes each word,
     * and prints the decoded data. If an error is detected, it tries to correct it.
     * @param filename The name of the file containing Hamming (7,4) code words.
     */
    void decodeFile(const std::string& filename);

        /**
     * @brief Decodes a single Hamming (7,4) code word.
     * Decodes the input 7-bit Hamming code word, correcting any single-bit errors
     * and extracting the data bits. If multiple errors are detected, it throws an exception.
     * @param code A 7-bit code word as a vector.
     * @return The 4-bit decoded data as a vector, or an error message if multiple errors are detected.
     */
    std::vector<int> decodeWord(const std::vector<int>& code);
    
    /**
     * @brief Multiplies a binary vector by a matrix (mod 2).
     * Performs matrix multiplication (mod 2) between a matrix and a vector for error detection.
     * @param matrix The Eigen matrix to multiply with.
     * @param vector The binary vector.
     * @return The resulting binary vector (mod 2).
     */
    std::vector<int> matrixMultiplyMod2(const Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>& matrix, const std::vector<int>& vector);

    /**
     * @brief Corrects a single-bit error in a 7-bit Hamming code word.
     * Flips the bit at the position of the error detected.
     * @param code A 7-bit code word as a vector.
     * @param errorPosition The 1-based position of the error bit.
     */
    void correctError(std::vector<int>& code, int errorPosition);

    /**
     * @brief Converts a binary vector to a string for display.
     * Converts a binary vector (e.g., {1, 0, 1}) to a string (e.g., "101").
     * @param vec The binary vector.
     * @return The string representation of the vector.
     */
    std::string vectorToString(const std::vector<int>& vec);

private:
    Eigen::Matrix<int, 4, 7> G; ///< Generator matrix.
    Eigen::Matrix<int, 3, 7> H; ///< Parity-check matrix.


};

#endif // HAMMINGCODE_H
