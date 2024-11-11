#ifndef homework3_h
#define homework3_h

#include <string>
#include <vector>

// Function to find common permutations of two strings.
// Returns a string containing the common characters from both strings.
std::string common_permutations(const std::string& a, const std::string& b);

// Function to calculate the total distance from all relatives houses to vito's house.
// Returns the total sum of distances.
int vitos_family(std::vector<int>& relatives);

// Function to count the number of carry operations during the addition of two integers.
// Returns a string describing the number of carry operations.
std::string primary_arithmetic(int num1, int num2);

#endif
