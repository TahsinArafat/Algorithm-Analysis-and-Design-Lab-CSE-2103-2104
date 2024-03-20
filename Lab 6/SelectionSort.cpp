#include <iostream>
using namespace std;
void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void Sort(int arr[], int i, int j)
{
    if (i == j)
        return;
    int maxVal = arr[i], maxIndex = i;
    for (int k = i + 1; k <= j; k++) {
        if (maxVal < arr[k]) {
            maxVal = arr[k], maxIndex = k;
        }
    }
    for (int k = maxIndex; k <= j - 1; k++)
        arr[k] = arr[k + 1];
    arr[j] = maxVal;
    PrintArray(arr, j);
    Sort(arr, i, j - 1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    PrintArray(arr, n);
    Sort(arr, 0, n - 1);
    PrintArray(arr, n);
}