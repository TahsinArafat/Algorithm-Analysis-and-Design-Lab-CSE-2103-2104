#include <iostream>
using namespace std;

void INSERTION_SORT(int arr[], int n) // INSERTION-SORT (A)
{
    for (int j = 1; j < n; j++) { // for j = 2 to A.length
        int key = arr[j]; // key = A[j]
        // Insert A[j] into the sorted sequence A[1… j-1]
        int i = j - 1; // i = j - 1
        while (i >= 0 && arr[i] > key) { // while i>0 and A[i] > key
            arr[i + 1] = arr[i]; // A[i+1] = A[i]
            i--; // i = i - 1
        }
        arr[i + 1] = key; // A[i + 1]  =  key
    }
}

int main()
{
    int n; // Length of the array
    cin >> n;
    int arr[n]; // Array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    INSERTION_SORT(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
/*
Psuedo Code:
INSERTION-SORT (A)
for j = 2 to A.length
    key = A[j]
    // Insert A [j] into the sorted sequence A[1… j-1]
    i = j - 1
    while i>0 and A[i] > key
        A[i+1] = A[i]
        i = i - 1
    A[i + 1]  =  key

*/
// Coded by Tahsin Arafat
// 07-02-2024