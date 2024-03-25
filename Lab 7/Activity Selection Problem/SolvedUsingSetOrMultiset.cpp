#include <iostream>
#include <set>
using namespace std;

int main()
{
    // freopen("Dataset.txt", "r", stdin);
    int n;
    cin >> n;
    set<pair<int, int>> st; // Multiset will also work, but here we are not using the duplicate values
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        st.insert({ end, start });
    }
    int ans = 0, lastEnd = -1;
    for (auto& it : st) {
        if (it.second > lastEnd) {
            ans++;
            lastEnd = it.first;
        }
    }
    cout << ans << "\n";
}