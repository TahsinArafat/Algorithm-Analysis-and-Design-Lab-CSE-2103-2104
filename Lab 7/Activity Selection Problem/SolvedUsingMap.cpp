#include <iostream>
#include <map>
using namespace std;

int main()
{
    // freopen("Dataset.txt", "r", stdin);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        mp[end] = max(mp[end], start);
    }
    int ans = 0, lastEnd = -1;
    for (auto& it : mp) {
        if (it.second > lastEnd) {
            ans++;
            lastEnd = it.first;
        }
    }
    cout << ans << "\n";
}