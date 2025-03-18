#include <iostream>
#include <cstring>
using namespace std;
struct Solution {
    const char* mapping[10] = {
        "",     "",     "abc",  "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    char** letterCombinations(const char* digits, int& returnSize, int& len) {
        len = strlen(digits);
        if (len == 0) {
            returnSize = 0;
            return nullptr;
        }
        int totalComb = 1;
        for (int i = 0; i < len; ++i) {
            int digit = digits[i] - '0';
            totalComb *= strlen(mapping[digit]);
        }
        char** result = new char*[totalComb];
        for (int i = 0; i < totalComb; ++i) {
            result[i] = new char[len];
        }
        returnSize = 0;
        char current[len];
        backtrack(digits, 0, len, current, result, returnSize);
        return result;
    }
private:
    void backtrack(const char* digits, int index, int len, char* current, char** result, int& returnSize) {
        if (index == len) {
            for (int i = 0; i < len; ++i) {
                result[returnSize][i] = current[i];
            }
            returnSize++;
            return;
        }
        int digit = digits[index] - '0';
        const char* letters = mapping[digit];
        for (int i = 0; letters[i] != '\0'; ++i) {
            current[index] = letters[i];
            backtrack(digits, index + 1, len, current, result, returnSize);
        }
    }
};
int main() {
    Solution solution;
    char digits[5];
    printf("Ingrese los dígitos: ");
    scanf("%s", digits);
    int returnSize = 0;
    int len = 0;
    char** combinations = solution.letterCombinations(digits, returnSize, len);
    printf("Posibles combinaciones:\n");
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%c", combinations[i][j]);
        }
        printf(" ");
        delete[] combinations[i];
    }
    printf("\n");
    delete[] combinations;
    return 0;
}

