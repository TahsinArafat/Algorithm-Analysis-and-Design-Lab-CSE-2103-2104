#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // freopen("Dataset.txt", "r", stdin);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        pq.push({ end, start });
    }
    int ans = 0, lastEnd = -1;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if (it.second > lastEnd) {
            ans++;
            lastEnd = it.first;
        }
    }
    cout << ans << "\n";
}