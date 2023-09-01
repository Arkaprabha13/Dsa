#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// using dfs

void DFS(vector<int> adj[], int u, stack<int> &st, bool visited[])
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v] == false)
            DFS(adj, v, st, visited);
    }
    st.push(u);
}

void topologicalSort_dfs(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    stack<int> st;

    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            DFS(adj, u, st, visited);
        }
    }

    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
}


// using bfs
void topologicalSort_bfs(vector<int> adj[], int V)
{
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int x : adj[u])
            in_degree[x]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : adj[u])
            if (--in_degree[x] == 0)
                q.push(x);
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Following is a Topological Sort of\n";
    topologicalSort_dfs(adj, V);

    return 0;
}
