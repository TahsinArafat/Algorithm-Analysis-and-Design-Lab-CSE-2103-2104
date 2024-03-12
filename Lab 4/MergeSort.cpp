#include <iostream>

using namespace std;

void merge(int array[], int left, int middle, int right) {
    int leftIndex, rightIndex, mergedIndex;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int Left[leftSize], Right[rightSize];

    for (leftIndex = 0; leftIndex < leftSize; leftIndex++)
        Left[leftIndex] = array[left + leftIndex];
    for (rightIndex = 0; rightIndex < rightSize; rightIndex++)
        Right[rightIndex] = array[middle + 1 + rightIndex];

    leftIndex = 0;
    rightIndex = 0;
    mergedIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (Left[leftIndex] <= Right[rightIndex]) {
            array[mergedIndex] = Left[leftIndex];
            leftIndex++;
        } else {
            array[mergedIndex] = Right[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize) {
        array[mergedIndex] = Left[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize) {
        array[mergedIndex] = Right[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << " ";

    mergeSort(array, 0, arraySize - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << " ";

    return 0;
}