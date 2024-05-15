#include <iostream>
#include <vector>
using namespace std;
#define int long long

bool isNegCycleFound(vector<vector<int>>& dist)
{
    int v = dist.size();
    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

void Solve()
{
    int v, e; // Nodes, Edges
    cin >> v >> e;
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX)); // Adjacency Matrix + Distance from every pair
    while (e--) {
        int a, b;
        cin >> a >> b;
        cin >> dist[a][b];
    }
    for (int i = 0; i < v; i++)
        dist[i][i] = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < v; k++) {
                if (dist[j][i] != INT_MAX && dist[i][k] != INT_MAX)
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
        if (isNegCycleFound(dist)) {
            cout << "Negative Cycle Found, no shortest path exists!\n";
            return;
        }
    }
    cout << "Every Pair Distance Graph:\n\n";
    cout << "S\\D|\t";
    for (int i = 0; i < v; i++)
        cout << i << (i == v - 1 ? '\n' : '\t');
    cout << "----------------------------------\n";
    for (int i = 0; i < v; i++) {
        cout << i << "  |\t";
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i][j];
            cout << (j == v - 1 ? '\n' : '\t');
        }
    }
}

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        Solve();
    }
    return 0;
}

/*
Demo input:

1
4 4
0 1 2
1 2 -1
2 3 0
1 3 1

*/