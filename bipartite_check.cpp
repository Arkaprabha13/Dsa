//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool check_bipartite(vector<int> graph[], vector<int> color, int node, int c)
    {
        color[node] = c;
        for (auto neighbour : graph[node])
        {
            if (color[neighbour] == -1)
            {
                // coloring the adjacent nodes;
                if (!check_bipartite(graph, color, neighbour, 1 - c))
                {
                    return false;
                }
            }
            else if (color[neighbour] == c)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int v, vector<int> graph[])
    {
        // coloring all elements -1
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!check_bipartite(graph, color, i, 0))
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends