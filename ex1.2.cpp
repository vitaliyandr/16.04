#include <iostream>

// Функція розподілу динамічної пам'яті
int* allocateMemory(int size) {
    int* arr = new int[size];
    return arr;
}

// Функція ініціалізації динамічного масиву
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

// Функція друку динамічного масиву
void printArray(int* arr, int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функція видалення динамічного масиву
void deleteArray(int* arr) {
    delete[] arr;
}

// Функція додавання елемента в кінець масиву
void addElementToEnd(int* arr, int& size, int element) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    size++;
    delete[] arr;
    arr = newArr;
}

// Функція вставки елемента за вказаним індексом
void insertElementAtIndex(int* arr, int& size, int index, int element) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index + 1; i < size + 1; i++) {
        newArr[i] = arr[i - 1];
    }
    size++;
    delete[] arr;
    arr = newArr;
}

// Функція видалення елемента за вказаним індексом
void deleteElementAtIndex(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Error: invalid index!" << std::endl;
        return;
    }

    int* newArr = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    size--;
    delete[] arr;
    arr = newArr;
}

int main() {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    int* arr = allocateMemory(size);
    initializeArray(arr, size);
    printArray(arr, size);

    // Приклад використання функцій додавання
    addElementToEnd(arr, size, 10);
    std::cout << "Array after adding element: ";
    printArray(arr, size);
    insertElementAtIndex(arr, size, 2, 20);
    std::cout << "Array after inserting element: ";
    printArray(arr, size);

    deleteElementAtIndex(arr, size, 1);
    std::cout << "Array after deleting element: ";
    printArray(arr, size);

    // Видалення динамічного масиву
    deleteArray(arr);

    return 0;
}