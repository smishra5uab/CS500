#include "hamming.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

HammingCode::HammingCode() {
    // Initialize the generator matrix G (4x7)
    G << 1, 1, 0, 1, 1, 0, 0,
         0, 1, 1, 1, 0, 1, 0,
         1, 1, 1, 0, 0, 0, 1,
         1, 0, 1, 1, 0, 0, 0;

    // Initialize the parity-check matrix H (3x7)
    H << 1, 0, 1, 0, 1, 0, 1,
         0, 1, 1, 0, 0, 1, 1,
         0, 0, 0, 1, 1, 1, 1;
}

/**
 * @brief Decodes a file containing Hamming (7,4) encoded words.
 * Reads the encoded data from a file, decodes each line, and prints the results.
 * It attempts to correct single-bit errors in the code words.
 * @param filename The name of the file containing Hamming (7,4) encoded code words.
 * @throws std::runtime_error if the file cannot be opened.
 */
void HammingCode::decodeFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> code;
        for (char c : line) {
            if (c == '0' || c == '1') {
                code.push_back(c - '0');
            }
        }

        if (code.size() != 7) {
            std::cerr << "Invalid code length: " << vectorToString(code) << std::endl;
            continue;
        }

        try {
            auto decoded = decodeWord(code);
            std::cout << "Original code: " << vectorToString(code)
                      << " -> Decoded data: " << vectorToString(decoded) << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Error decoding: " << e.what() << std::endl;
        }
    }
}

std::vector<int> HammingCode::decodeWord(const std::vector<int>& code) {
    if (code.size() != 7) {
        throw std::runtime_error("Invalid code length: " + vectorToString(code));
    }

    // Check for all-one code, which is uncorrectable
    if (std::all_of(code.begin(), code.end(), [](int bit) { return bit == 1; })) {
        throw std::runtime_error("Multiple errors detected, cannot correct.");
    }

    // Create a copy to modify
    std::vector<int> modifiedCode = code;

    std::vector<int> syndrome = matrixMultiplyMod2(H, modifiedCode);

    // Calculate the error position
    int errorPosition = 0;
    for (int i = 0; i < 3; ++i) {
        errorPosition |= (syndrome[i] << (2 - i));
    }

    // Correct the error if necessary
    if (errorPosition > 0) {
        if (errorPosition <= 7) {
            modifiedCode[errorPosition - 1] ^= 1;
        } else {
            throw std::runtime_error("Invalid syndrome, cannot correct error.");
        }
    }

    // Extract the data bits
    return {modifiedCode[0], modifiedCode[1], modifiedCode[3], modifiedCode[4]};
}

void HammingCode::correctError(std::vector<int>& code, int errorPosition) {
    // Flip the bit at the error position (adjusted for 1-based indexing)
    if (errorPosition > 0 && errorPosition <= 7) {
        code[errorPosition - 1] ^= 1;  // Flip the bit at errorPosition (0-based index)
    }
}



std::vector<int> HammingCode::matrixMultiplyMod2(const Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>& matrix, const std::vector<int>& vector) {
    // Ensure the dimensions match (matrix cols should match vector size)
    if (matrix.cols() != vector.size()) {
        throw std::runtime_error("Matrix dimensions do not match vector size.");
    }

    Eigen::VectorXi vec(vector.size());
    for (size_t i = 0; i < vector.size(); ++i) {
        vec[i] = vector[i];
    }

    Eigen::VectorXi result = (matrix * vec).unaryExpr([](int x) { return x % 2; });

    std::vector<int> resultVec(result.size());
    for (int i = 0; i < result.size(); ++i) {
        resultVec[i] = result[i];
    }

    return resultVec;
}



std::string HammingCode::vectorToString(const std::vector<int>& vec) {
    std::ostringstream oss;
    for (int bit : vec) {
        oss << bit;
    }
    return oss.str();
}