#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int mergedArray[r - l + 1], i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
        if (arr[i] <= arr[j])
            mergedArray[k++] = arr[i++];
        else
            mergedArray[k++] = arr[j++];
    while (i <= m)
        mergedArray[k++] = arr[i++];
    while (j <= r)
        mergedArray[k++] = arr[j++];
    for (int z = l; z <= r; z++)
        arr[z] = mergedArray[z - l];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid), mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}