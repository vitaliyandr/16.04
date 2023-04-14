#include <iostream>

int* removeNegativeNumbers(int* arr, int size) {
    int* newArr = new int[size]; 
    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            newArr[count] = arr[i]; 
            count++;
        }
    }

    return newArr;
}