//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // Function to detect cycle in a directed graph.
bool DFS(vector<int> adj[], int s, bool visited[], bool rec_stack[]) {
    visited[s] = true;
    rec_stack[s] = true;
    
    for (int neighbour : adj[s]) {
        if (visited[neighbour] == false) {
            if (DFS(adj, neighbour, visited, rec_stack) == true) {
                return true;
            }
        } else if (rec_stack[neighbour] == true) {
            return true;
        }
    }
    
    rec_stack[s] = false;
    return false;
}

    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        bool visited[v];
        bool rec_stack[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
            rec_stack[i]=false;
        }
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
               if(DFS(adj,i,visited,rec_stack)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
