#include <iostream>

int* insertElements(int* arr, int size, int* elements, int numElements, int index) {
    int* newArr = new int[size + numElements]; // Динамічний масив для нових елементів

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i]; // Копіюємо елементи перед вставкою в новий масив
    }

    for (int i = 0; i < numElements; i++) {
        newArr[index + i] = elements[i]; // Вставляємо нові елементи у вказаний індекс нового масиву
    }

    for (int i = index; i < size; i++) {
        newArr[numElements + i] = arr[i]; // Копіюємо елементи після вставки в новий масив
    }

    return newArr;
}