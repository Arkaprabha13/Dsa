#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
    void bfs(T source)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int front_node = q.front();
            q.pop();
            cout << front_node << " ";

            // Insert neighbors
            for (int neighbour : adjList[front_node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour); // You should push 'neighbour', not 'visited[neighbour]'
                    visited[neighbour] = true;
                }
            }
        }
    }
    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
    bool check_cyclic_using_bfs(int source, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty())
        {
            int front_node = q.front();
            q.pop();

            for (auto neighbours : adjList[front_node])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                    parent[neighbours] = front_node;
                }
                else
                {
                    // already visited
                    if (neighbours != parent[front_node])
                    {
                        // cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool check_cyclic_using_dfs(int source, unordered_map<int, bool> &visited, int parent)
    {
        visited[source] = true;

        for (auto neighbour : adjList[source])
        {
            if (!visited[neighbour])
            {
                bool check_nxt_ans = check_cyclic_using_dfs(neighbour, visited, source);
                if (check_nxt_ans == true)
                {
                    return true;
                }
                if (visited[neighbour] == true && neighbour != parent)
                {
                    return true;
                    // cycle present
                }
            }
            return false;
        }
    }
    bool check_directed_graph_is_cycle_or_not(int source, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs_visited, int parent)
    {
        visited[source] = true;
        dfs_visited[source] = true;
        for (auto neighbour : adjList[source])
        {
            if (!visited[neighbour])
            {
                bool check_nxt_ans = check_directed_graph_is_cycle_or_not(neighbour, visited, dfs_visited, source);
                if (check_nxt_ans == true)
                {
                    return true;
                }
            }
            if (visited[neighbour] == true && dfs_visited[neighbour] == true)
            {
                return true;
            }
        }
        dfs_visited[source] = false;
        return false;
    }
    void topological_sort_using_DFS(int source, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[source] = true;

        for (auto neighbour : adjList[source])
        {
            if (!visited[neighbour])
            {
                topological_sort_using_DFS(neighbour, visited, ans);
            }
        }
        ans.push(source);
    }
    void topological_sort_using_bfs(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // getting indegree of all

        for (auto i : adjList)
        {
            int source = i.first;
            for (auto neighbour : i.second)
            {
                indegree[neighbour]++;
            }
        }

        // putting all node for indegree 0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs logic
        while (!q.empty())
        {
            int fornt_node = q.front();
            q.pop();

            // cout << fornt_node << " ";
            ans.push_back(fornt_node);
            for (auto neighbour : adjList[fornt_node])
            {
                indegree[neighbour]--;
                // check for zero again
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
    }
};
int main()
{
    Graph<int> g;
    unordered_map<int, bool> visited;
    stack<int> ans;
    int n = 8;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.printAdjacencyList();
    cout << endl;

    // for DFS
    cout << "Topological sort using DFS" << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topological_sort_using_DFS(i, visited, ans);
        }
    }
    while (!ans.empty())
    {

        cout << ans.top() << " ";
        ans.pop();
    }

    // For BFS

    vector<int> ans_bfs;
    g.topological_sort_using_bfs(n, ans_bfs);
    cout << "\nTopological sort using BFS" << endl; // KAHNS Algorithm
    for (auto it : ans_bfs)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
