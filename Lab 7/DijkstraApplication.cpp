#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main()
{
    /*
    // Input
    7
    11

    1 3 3
    1 4 4
    1 5 4
    2 3 2
    2 6 2
    3 5 4
    3 7 5
    3 6 5
    4 5 2
    5 7 5
    6 7 5
    */
    int n; // Number of Nodes
    cin >> n;
    vector<pair<int, int>> graph[n + 1]; // Pair.first = node, Pair.second = weight
    int edges; // Number of Edges
    cin >> edges;
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st; // Pair.first = weight distance from source, Pair.second = node
    st.push({ 0, 1 });
    dist[1] = 0;
    while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        for (auto& it : graph[cur.second]) {
            if (dist[it.first] > dist[cur.second] + it.second) {
                dist[it.first] = dist[cur.second] + it.second;
                st.push({ dist[it.first], it.first });
            }
        }
    }
    // Source Node is 1
    cout << "Node\tDistance\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " (" << (char)('A' + i - 1) << ")\t" << dist[i] << "\n";
    }
}