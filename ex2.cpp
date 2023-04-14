#include <iostream>

void countPositiveNegativeZero(int* arr, int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int main() {
    int arr[] = { 1, -2, 0, 3, -1, 4, 0, -5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int positiveCount, negativeCount, zeroCount;
    countPositiveNegativeZero(arr, size, positiveCount, negativeCount, zeroCount);

    std::cout << "Positive Count: " << positiveCount << std::endl;
    std::cout << "Negative Count: " << negativeCount << std::endl;
    std::cout << "Zero Count: " << zeroCount << std::endl;

    return 0;
}