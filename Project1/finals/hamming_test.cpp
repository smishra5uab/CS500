#include "gtest/gtest.h"
#include "hamming.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Test HammingCode::decodeWord for valid codeword (no errors)
TEST(HammingCodeTest, DecodeValidCodeword) {
    HammingCode hamming;
    std::vector<int> code = {1, 0, 1, 1, 0, 1, 0}; // Valid Hamming (7,4) code
    auto result = hamming.decodeWord(code);
    EXPECT_EQ(result, std::vector<int>({1, 0, 1, 0}));
}

// Test HammingCode::decodeWord for single-bit error correction
TEST(HammingCodeTest, DecodeSingleBitError) {
    HammingCode hamming;
    std::vector<int> code = {1, 0, 1, 1, 1, 1, 1}; // Error in 4th bit
    auto result = hamming.decodeWord(code);
    EXPECT_EQ(result, std::vector<int>({1, 1, 1, 1}));
}

// Test HammingCode::decodeWord for even parity codeword (no errors)
TEST(HammingCodeTest, DecodeEvenParityCode) {
    HammingCode hamming;
    std::vector<int> code = {1, 0, 1, 0, 1, 1, 1};  // Valid codeword with even parity
    auto result = hamming.decodeWord(code);  
    EXPECT_EQ(result, std::vector<int>({1, 0, 1, 0}));  // Expected decoded data: 1010
}

// Test HammingCode::matrixMultiplyMod2 for correct multiplication
TEST(HammingCodeTest, MatrixMultiplyMod2) {
    HammingCode hamming;
    Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> matrix(3, 7);
    matrix << 1, 0, 1, 0, 1, 0, 1,
              0, 1, 1, 0, 0, 1, 1,
              0, 0, 0, 1, 1, 1, 1;
    std::vector<int> vector = {1, 0, 1, 0, 1, 1, 1};
    auto result = hamming.matrixMultiplyMod2(matrix, vector);
    EXPECT_EQ(result, std::vector<int>({0, 1, 1}));
}

// Test HammingCode::correctError for valid error correction
TEST(HammingCodeTest, CorrectError) {
    HammingCode hamming;
    std::vector<int> code = {1, 0, 1, 1, 1, 1, 1}; // Error in 4th bit
    hamming.correctError(code, 4);
    EXPECT_EQ(code, std::vector<int>({1, 0, 1, 0, 1, 1, 1}));
}

// Test HammingCode::correctError for no error
TEST(HammingCodeTest, CorrectErrorNoChange) {
    HammingCode hamming;
    std::vector<int> code = {1, 0, 1, 0, 1, 1, 1}; // No errors
    hamming.correctError(code, 0);
    EXPECT_EQ(code, std::vector<int>({1, 0, 1, 0, 1, 1, 1}));
}

// Test HammingCode::vectorToString
TEST(HammingCodeTest, VectorToString) {
    HammingCode hamming;
    std::vector<int> vec = {1, 0, 1, 0, 1, 1, 1};
    EXPECT_EQ(hamming.vectorToString(vec), "1010111");
}

// Test HammingCode::decodeFile for invalid file
TEST(HammingCodeTest, DecodeFileInvalid) {
    HammingCode hamming;
    EXPECT_THROW(hamming.decodeFile("nonexistent_file.txt"), std::runtime_error);
}

// New: Test HammingCode::decodeWord for single-bit error in a parity bit
TEST(HammingCodeTest, DecodeSingleBitErrorInParity) {
    HammingCode hamming;
    std::vector<int> code = {1, 1, 1, 0, 1, 0, 0}; // Error in 2nd bit (parity bit)
    auto result = hamming.decodeWord(code);
    EXPECT_EQ(result, std::vector<int>({1, 0, 1, 0}));
}

// New: Test HammingCode::decodeWord for a valid codeword with minimum data
TEST(HammingCodeTest, DecodeMinimumValidCode) {
    HammingCode hamming;
    std::vector<int> code = {0, 0, 0, 0, 0, 0, 0}; // Minimum valid Hamming code
    auto result = hamming.decodeWord(code);
    EXPECT_EQ(result, std::vector<int>({0, 0, 0, 0}));
}

// New: Test HammingCode::matrixMultiplyMod2 with an identity matrix
TEST(HammingCodeTest, MatrixMultiplyMod2IdentityMatrix) {
    HammingCode hamming;
    Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> identity(7, 7);
    identity.setIdentity();
    std::vector<int> vector = {1, 0, 1, 0, 1, 1, 1};
    auto result = hamming.matrixMultiplyMod2(identity, vector);
    EXPECT_EQ(result, vector); // Result should be the same as input vector
}

// New: Test HammingCode::decodeFile for a large file with valid codewords
TEST(HammingCodeTest, DecodeFileLargeValid) {
    HammingCode hamming;
    std::ofstream file("large_valid_file.txt");
    for (int i = 0; i < 1000; ++i) {
        file << "1010111\n"; // Valid codeword repeated
    }
    file.close();

    testing::internal::CaptureStdout();
    hamming.decodeFile("large_valid_file.txt");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Decoded data: 1111"), std::string::npos);
    std::remove("large_valid_file.txt");
}

// Test empty vector to decodeWord
TEST(HammingCodeTest, DecodeEmptyVector) {
    HammingCode hamming;
    EXPECT_THROW(hamming.decodeWord({}), std::runtime_error);
}

// Test HammingCode::decodeWord for zero-filled code
TEST(HammingCodeTest, DecodeAllZeroCode) {
    HammingCode hamming;
    std::vector<int> code = {0, 0, 0, 0, 0, 0, 0};
    auto result = hamming.decodeWord(code);
    EXPECT_EQ(result, std::vector<int>({0, 0, 0, 0}));
}

// Test HammingCode::decodeWord for all-one code
TEST(HammingCodeTest, DecodeAllOneCode) {
    HammingCode hamming;
    std::vector<int> code = {1, 1, 1, 1, 1, 1, 1}; // Multiple errors
    EXPECT_THROW(hamming.decodeWord(code), std::runtime_error);
}
