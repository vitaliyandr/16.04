#include <iostream>

int* appendElementsToEnd(int* arr, int size, int* elements, int numElements) {
    int* newArr = new int[size + numElements]; 

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i]; 
    }

    for (int i = 0; i < numElements; i++) {
        newArr[size + i] = elements[i]; 
    }

    return newArr;
}