#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int W, pair<int, int> arr[], int n)
{
    sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // Larger Values First
    });
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (W >= arr[i].first) {
            ans += arr[i].second;
            W -= arr[i].first;
        }
    }
    return ans;
}

int main()
{
    int W = 50; // Max Weight
    pair<int, int> arr[] = { { 20, 100 }, { 30, 120 }, { 10, 60 } }; // { Weight, Value }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << UnboundedKnapsack(W, arr, n);
    return 0;
}