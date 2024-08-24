#include <iostream>
#include <limits>

void reverseCopyArray(const int* source, int* destination, int size) {
    const int* srcPtr = source + size - 1;
    int* destPtr = destination;

    for (int i = 0; i < size; ++i) {
        *destPtr = *srcPtr;
        ++destPtr;
        --srcPtr;
    }
}

void findMinMax(const int* array, int size, int& min, int& max) {
    const int* ptr = array;

    min = std::numeric_limits<int>::max();
    max = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (*ptr < min) min = *ptr;
        if (*ptr > max) max = *ptr;
        ++ptr;
    }
}

void rotateArray(int* array, int size, int shift, bool direction) {
    int* temp = new int[size];

    for (int i = 0; i < size; ++i) {
        temp[i] = *(array + i);
    }

    if (direction) {
        for (int i = 0; i < size; ++i) {
            *(array + (i + shift) % size) = temp[i];
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            *(array + i) = temp[(i + size - shift) % size];
        }
    }

    delete[] temp;
}

int main() {
    const int size = 5;

    int sourceArray[size] = { 1, 2, 3, 4, 5 };
    int destinationArray[size];

    reverseCopyArray(sourceArray, destinationArray, size);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив в обратном порядке: ";
    for (int i = 0; i < size; ++i) {
        std::cout << destinationArray[i] << " ";
    }
    std::cout << std::endl;

    int array2[size] = { 3, 1, 7, 9, 2 };
    int min, max;

    findMinMax(array2, size, min, max);

    std::cout << "Минимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;

    int array3[size] = { 1, 2, 3, 4, 5 };
    int shift;
    char direction;

    std::cout << "Введите количество элементов для сдвига: ";
    std::cin >> shift;
    shift = shift % size;

    std::cout << "Введите направление (влево/вправо) (l/r): ";
    std::cin >> direction;

    bool isRight = (direction == 'r');


