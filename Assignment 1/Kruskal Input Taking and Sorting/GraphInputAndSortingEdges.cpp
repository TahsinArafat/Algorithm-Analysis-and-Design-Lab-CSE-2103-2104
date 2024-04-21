#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

bool Comparator(Edge& a, Edge& b)
{
    return a.w < b.w;
}

void PrintAllEdges(vector<Edge>& edges)
{
    int n = edges.size();
    cout << "U\tV\tWeight\n";
    for (int i = 0; i < n; i++) {
        cout << edges[i].u << "\t" << edges[i].v << "\t" << edges[i].w << '\n';
    }
}
int32_t main()
{
    int n; // Number of Edges of the graph
    cin >> n;
    // vector<pair<int, int>> graph[n + 1];
    vector<Edge> edges(n);
    // Taking input of the edges of the graph
    for (auto& it : edges) {
        cin >> it.u >> it.v >> it.w; // u, v, w are the vertices and weight of the edge
        // graph[it.u].push_back({ it.v, it.w });
        // graph[it.v].push_back({ it.u, it.w });
    }
    // Sorting them by weight in non-decreasing order
    sort(edges.begin(), edges.end(), Comparator);
    PrintAllEdges(edges);
    return 0;
}