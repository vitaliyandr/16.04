#include <iostream>
#include <cmath>

// Функція для перевірки, чи є число простим
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Функція для видалення простих чисел з масиву
int* removePrimes(int* arr, int size) {
    int* newArr = new int[size]; // Створюємо новий динамічний масив
    int newSize = 0; // Розмір нового масиву

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) { // Якщо елемент не є простим числом
            newArr[newSize] = arr[i]; // Додаємо його до нового масиву
            newSize++; // Збільшуємо розмір нового масиву
        }
    }

    // Змінюємо розмір нового масиву на фактичний розмір
    int* result = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        result[i] = newArr[i];
    }

    delete[] newArr; // Видаляємо допоміжний масив

    return result; // Повертаємо новий масив без простих чисел
}

int main() {
    int size = 6;
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int* resultArr = removePrimes(arr, size);

    std::cout << "Array after removing primes: ";
    for (int i = 0; i < size - 1; i++) {
        std::cout << resultArr[i] << " ";
    }
    std::cout << resultArr[size - 1] << std::endl;

    delete[] resultArr; // Видаляємо новий масив

    return 0;
}
