#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> key(V, INT_MAX);
    vector<bool> mSet(V, false);
    key[0] = 0;
    int res = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!mSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mSet[u] = true;
        res += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mSet[v]) {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int minimumCost = primMST(graph);

    cout << "Minimum Cost of MST: " << minimumCost << endl;

    return 0;
}
