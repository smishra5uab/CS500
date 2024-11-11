#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

/* Function: common_permutations()
 * =============================
 * Logic: we declare arrays for storing the number of occurence of each character in a and b with
 * length 26 (count of alphabets).
 * compare the counts of each letter that is common in both words and take the smallest count
 * between the two words and store in the result string.
 * Here, since we are going by index (the order of alphabets) directly, 
 * Finally, return resultant string.
 */
std::string common_permutations(const std::string& a, const std::string& b) {
    int a_count[26] = {0};
    int b_count[26] = {0};

    for (char c : a) a_count[c - 'a']++;
    for (char c : b) b_count[c - 'a']++;

    std::string result;
    for (int i = 0; i < 26; ++i) {
        int common = std::min(a_count[i], b_count[i]);
        result += std::string(common, 'a' + i);
    }

    return result;
}

/*
 * Function: vitos_family()
 * ==========================
 * Logic: simplest solution to this is to find a median house number and then calculate the total
 * distance from median to each relative's house. For an even number of relatives, just divide by 2.
 */
int vitos_family(std::vector<int>& relatives) {
    std::sort(relatives.begin(), relatives.end());
    int median = relatives[relatives.size() / 2];
    int distance_sum = 0;

    for (int r : relatives) {
        distance_sum += std::abs(r - median);
    }

    return distance_sum;
}

/*
 * Function: primary_arithmetic()
 * ===============================
 * Logic: Process the digits from right to left (least to most significant) and add the carry from
 * each addition. Maintain a counter of how many times the sum exceeds 9 and increase the counter.
 */
std::string primary_arithmetic(int num1, int num2) {
    int carry = 0, carry_count = 0;

    while (num1 > 0 || num2 > 0) {
        int sum = (num1 % 10) + (num2 % 10) + carry;
        if (sum >= 10) {
            carry = 1;
            carry_count++;
        } else {
            carry = 0;
        }
        num1 /= 10;
        num2 /= 10;
    }

    if (carry_count == 0) return "No carry operation.";
    else if (carry_count == 1) return "1 carry operation.";
    else return std::to_string(carry_count) + " carry operations.";
}

