#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void PrintPath(vector<int>& path, int node)
{
    if (node == -1)
        return;
    PrintPath(path, path[node]);
    cout << node << ' ';
}

void BFS(vector<int> graph[], bool isVisited[], int node, vector<int>& path, vector<int>& weight)
{
    queue<int> q;
    q.push(node);
    weight[node] = 0;
    cout << "BFS Traversal : ";
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        isVisited[cur] = true;
        q.pop();
        for (auto& it : graph[cur])
            if (!isVisited[it]) {
                q.push(it);
                path[it] = cur;
                weight[it] = weight[cur] + 1;
            }
    }
    cout << "\n\n";
}

int main()
{
    // Dummy Input:
    /*
    5
    6
    2 1
    1 0
    0 3
    0 4
    3 5
    4 5
    */
    int n; // Highest Node
    cin >> n;
    vector<int> graph[n + 2], path(n + 1, -1), weight(n + 1, -1);
    bool isVisited[n + 1] = { false };
    int m; // Edges
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(graph, isVisited, 0, path, weight);
    path[0] = -1;
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