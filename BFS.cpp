#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[], int v, int s)
{
    bool visitd[v + 1];
    for (int i = 0; i < v; i++)
    {
        visitd[i] = false;
    }
    visitd[s] = true;
    queue<int> q;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : adj[u])
        {
            if (visitd[v] == false)
            {
                visitd[v] = true;
                q.push(v);
            }
        }
    }
}
// . B.F.S on disconnected graphs.
void BFS(vector<int> adj[], int s, bool visited[])
{

    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFS_disconnected(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
        }
    }
}
int BFSDin(vector<int> adj[], int V)
{
    bool visited[V];
    int count = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
            count++;
        }
    }

    return count;
}
void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V1 = 5;
    vector<int> adj1[V1];
    add_edge(adj1, 0, 1);
    add_edge(adj1, 0, 2);
    add_edge(adj1, 1, 2);
    add_edge(adj1, 2, 3);
    add_edge(adj1, 1, 3);
    add_edge(adj1, 3, 4);
    add_edge(adj1, 2, 4);
    int V2 = 7;
    vector<int> adj2[V2];
    add_edge(adj2, 0, 1);
    add_edge(adj2, 0, 2);
    add_edge(adj2, 2, 3);
    add_edge(adj2, 1, 3);
    add_edge(adj2, 4, 5);
    add_edge(adj2, 5, 6);
    add_edge(adj2, 4, 6);

    int V3 = 7;
    vector<int> adj3[V3];
    add_edge(adj3, 0, 1);
    add_edge(adj3, 0, 2);
    add_edge(adj3, 2, 3);
    add_edge(adj3, 1, 3);
    add_edge(adj3, 4, 5);
    add_edge(adj3, 5, 6);
    add_edge(adj3, 4, 6);

    cout << "Following is Breadth First Traversal: " << endl;
    BFS(adj1, V1, 0);
    cout << "\n For disconnected without source Following is Breadth First Traversal: " << endl;
    BFS_disconnected(adj2, V2);

    cout << "\n\nNumber of islands: " << BFSDin(adj3, V3);
    return 0;
}