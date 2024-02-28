#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define x first
#define y second
void PrintPath(vector<int>& path, int node)
{
    if (node == -1)
        return;
    PrintPath(path, path[node]);
    cout << node << ' ';
}

void Dijkstra(vector<pair<int, int>> graph[], vector<int>& path, vector<int>& weight)
{
    set<pair<int, int>> s;
    s.insert({ 0, 0 }); // Weight, node
    weight[0] = 0;
    while (!s.empty()) {
        pair<int, int> curNode = *s.begin();
        s.erase(s.begin());
        for (auto& child : graph[curNode.y]) {
            if (weight[child.x] > weight[curNode.y] + child.y) {
                weight[child.x] = weight[curNode.y] + child.y;
                path[child.x] = curNode.y;
                s.insert({ weight[child.x], child.x });
            }
        }
    }
}

int main()
{
    // Dummy Input
    /*
    5
    6
    2 1 3
    1 0 2
    0 3 2
    0 4 1
    3 5 5
    4 5 1
    */
    int n; // Highest Node
    cin >> n;
    vector<pair<int, int>> graph[n + 2];
    vector<int> path(n + 1, -1), weight(n + 1, 1e9);
    //---------//
    int m; // Edges
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; // node1, node2, weight
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    //---------//
    Dijkstra(graph, path, weight);
    // Path, Weight Printing
    for (int i = 0; i <= n; i++) {
        if (weight[i] == -1)
            continue;
        cout << "Node: " << i << '\n';
        cout << "Weight: " << weight[i] << '\n';
        cout << "Path: ";
        PrintPath(path, i);
        cout << "\n\n";
    }
}