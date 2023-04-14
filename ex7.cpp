#include <iostream>

void deleteBlock(int* arr, int& size, int index, int numElements) {
    if (index < 0 || index >= size) {
        std::cout << "Error: invalid index!" << std::endl;
        return;
    }

    if (numElements <= 0) {
        std::cout << "Error: invalid number of elements to delete!" << std::endl;
        return;
    }

    if (index + numElements > size) {
        std::cout << "Error: number of elements to delete exceeds the size of the array!" << std::endl;
        return;
    }

    for (int i = index; i < size - numElements; i++) {
        arr[i] = arr[i + numElements];
    }

    size -= numElements;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    deleteBlock(arr, size, 2, 3);

    std::cout << "Array after deletion: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
