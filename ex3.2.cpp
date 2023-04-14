#include <iostream>

void separateElements(int* arr, int size, int*& positiveArr, int& positiveSize,
    int*& negativeArr, int& negativeSize, int*& zeroArr, int& zeroSize) {
    // Ініціалізуємо розміри динамічних масивів
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    // Перераховуємо елементи статичного масиву
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveSize++;
        }
        else if (arr[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }

    // Виділяємо пам'ять для динамічних масивів
    positiveArr = new int[positiveSize];
    negativeArr = new int[negativeSize];
    zeroArr = new int[zeroSize];

    // Заповнюємо динамічні масиви
    int positiveIndex = 0;
    int negativeIndex = 0;
    int zeroIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveArr[positiveIndex++] = arr[i];
        }
        else if (arr[i] < 0) {
            negativeArr[negativeIndex++] = arr[i];
        }
        else {
            zeroArr[zeroIndex++] = arr[i];
        }
    }
}

int main() {
    int arr[] = { -2, 0, 5, -10, 7, 0, -3, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* positiveArr;
    int positiveSize;
    int* negativeArr;
    int negativeSize;
    int* zeroArr;
    int zeroSize;

    separateElements(arr, size, positiveArr, positiveSize, negativeArr, negativeSize, zeroArr, zeroSize);

    // Виводимо розділені масиви на екран
    std::cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; i++) {
        std::cout << positiveArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; i++) {
        std::cout << negativeArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; i++) {
        std::cout << zeroArr[i] << " ";
    }
    std::cout << std::endl;

    // Звільняємо пам'ять виділену для динамічних масивів
    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;

    return 0;
}
