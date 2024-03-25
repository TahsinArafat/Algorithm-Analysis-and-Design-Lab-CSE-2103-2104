#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // freopen("Dataset.txt", "r", stdin);
    int n;
    cin >> n;
    pair<int, int> arr[n]; // Or Vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n); // Custom Sort Can Be Used Here // Or Vector Sort
    int ans = 0, lastEnd = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].second > lastEnd) {
            ans++;
            lastEnd = arr[i].first;
        }
    }
    cout << ans << "\n";
    return 0;
}