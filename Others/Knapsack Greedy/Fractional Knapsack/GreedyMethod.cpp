#include <bits/stdc++.h>
using namespace std;

double FractionalKnapsack(int W, pair<int, int> arr[], int n)
{
    double maxRatio = 0;
    for (int i = 0; i < n; i++) {
        maxRatio = max(maxRatio, (double)arr[i].second / arr[i].first);
    }
    return maxRatio * W;
}

int main()
{
    int W = 50; // Max Weight
    pair<int, int> arr[] = { { 20, 100 }, { 30, 120 }, { 10, 60 } }; // { Weight, Value }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << FractionalKnapsack(W, arr, n);
    return 0;
}