#include <iostream>

int* findSubset(int* A, int sizeA, int* B, int sizeB) {
    int* result = nullptr; 
    int i = 0; 

    while (i < sizeA) {
        int j = 0; 
        int k = i; 

        while (k < sizeA && j < sizeB && A[k] == B[j]) {
            k++;
            j++;
        }

        if (j == sizeB) {
            result = &A[i];
            break;
        }

        i++;
    }

    return result;
}

int main() {
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int B[] = { 4, 5, 6 };

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    int* result = findSubset(A, sizeA, B, sizeB);

    if (result != nullptr) {
        std::cout << "Subset found at index: " << result - A << std::endl;
    }
    else {
        std::cout << "Subset not found" << std::endl;
    }

    return 0;
}