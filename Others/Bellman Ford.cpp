#include <iostream>
#include <vector>
using namespace std;

int32_t main()
{
    int n; // Number of Nodes
    cin >> n;
    int m; // Number of Edges
    cin >> m;
    vector<int> visNodes;
    vector<pair<int, int>> graph[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w; // node, node, edge
        graph[u].push_back({ v, w });
    }
    vector<int> dist(n + 1, INT_MAX);
    int startNode = 0;
    dist[startNode] = 0;
    visNodes.push_back(startNode);
    int remainingIterations = n - 1;
    while (remainingIterations-- > 0) {
        vector<int> newVisNodes;
        for (auto& it : visNodes) {
            for (auto& it2 : graph[it]) {
                if (dist[it2.first] > dist[it] + it2.second) {
                    dist[it2.first] = dist[it] + it2.second;
                    newVisNodes.push_back(it2.first);
                }
            }
        }
        visNodes = newVisNodes;
    }
    bool isNegativeCycle = false;
    for (auto& it : visNodes) {
        for (auto& it2 : graph[it]) {
            if (dist[it2.first] > dist[it] + it2.second) {
                isNegativeCycle = true;
                break;
            }
        }
    }
    if (isNegativeCycle) {
        cout << "Negative Cycle Detected, No Shortest Path\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
