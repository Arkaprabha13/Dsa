#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjacency_list;
    unordered_map<int, list<int>> adjacency_list_for_bfs_dfs;

    void add_edge(int u, int v, int weight, bool direction)
    {
        // direction == 0 for undirected graph
        // direction == 1 for directed graph
        adjacency_list[u].push_back({v, weight}); // creating the 1st edge for the graph which is required for both directed and undirected

        // if it is an undirected graph then only we need another edge back to it
        if (direction == 0)
        {
            adjacency_list[v].push_back({u, weight});
        }
    }
    void add_edge(int u, int v, bool direction)
    {
        // direction == 0 for undirected graph
        // direction == 1 for directed graph
        adjacency_list_for_bfs_dfs[u].push_back(v); // creating the 1st edge for the graph which is required for both directed and undirected

        // if it is an undirected graph then only we need another edge back to it
        if (direction == 0)
        {
            adjacency_list_for_bfs_dfs[v].push_back(u);
        }
    }
    void print_list()
    {
        for (auto node : adjacency_list)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << " ( " << neighbour.first << " , " << neighbour.second << " ),";
            }
            cout << endl;
        }
    }
    void print_list_without_weight()
    {
        for (auto node : adjacency_list_for_bfs_dfs)
        {
            cout << node.first << " -> ";
            for (int neighbour : node.second)
            {
                cout << neighbour << " , ";
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) //! q.empty()
        {
            int front_node = q.front();
            q.pop();
            cout << front_node << " ";

            // inserting the neighbours
            for (int neighbour : adjacency_list_for_bfs_dfs[front_node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void dfs(int source, unordered_map<int, bool> &visited)
    {
        cout << source << " , ";
        visited[source] = true;
        for (int neighbour : adjacency_list_for_bfs_dfs[source])
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

            for (auto neighbours : adjacency_list_for_bfs_dfs[front_node])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                    parent[neighbours] = front_node;
                }
                else
                {
                    // dekha hoy geche
                    if (neighbours != parent[front_node])
                    {
                        // cycle ache
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool check_using_dfs(int source, unordered_map<int, bool> &visited, int parent)
    {
        visited[source] = true;
        for (auto neighbour : adjacency_list_for_bfs_dfs[source])
        {
            if (!visited[neighbour])
            {
                bool check_next_ans = check_using_dfs(neighbour, visited, source);
                if (check_next_ans == true)
                {
                    return true;
                }
                if (visited[neighbour] == true && neighbour != parent)
                {
                    return true;
                }
            }
        }
    }

    // for directed graph checking a cycle
    bool check_directed_graph_is_cyclic_or_not(int source, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs_visited, int parent)
    {
        visited[source] = true;
        dfs_visited[source] = true;
        for (auto neighbour : adjacency_list_for_bfs_dfs[source])
        {
            if (!visited[neighbour])
            {
                bool check_next_ans = check_directed_graph_is_cyclic_or_not(neighbour, visited, dfs_visited, source);
                if (check_next_ans == true)
                {
                    return true;
                }
            }
            if (visited[neighbour] == true && dfs_visited[neighbour] == true)
            {
                return true;
            }
        }
        dfs_visited[source] = true;
        return false;
    }
    void topological_sort_dfs(int source, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[source] = true;
        for (auto neighbour : adjacency_list_for_bfs_dfs[source])
        {
            if (!visited[neighbour])
            {
                topological_sort_dfs(neighbour, visited, ans);
            }
        }
        ans.push(source);
    }
    void topological_sort_bfs(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        // indegree calculate krbo sobar
        for (auto i : adjacency_list_for_bfs_dfs)
        {
            int source = i.first;
            for (auto neighbour : i.second)
            {
                indegree[neighbour]++;
            }
        }

        // sob node gulo k push krchi jader 0 indegree
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front_node = q.front();
            q.pop();
            ans.push_back(front_node);
            for (auto neighbour : adjacency_list_for_bfs_dfs[front_node])
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
vector<vector<int>> create_adjacency_matrix(int number_of_edges, int number_of_nodes)
{
    // nodes = vertices
    vector<vector<int>> adj_matrix(number_of_nodes, vector<int>(number_of_edges, 0));
    for (int i = 0; i < number_of_edges; i++)
    {
        int u, v;
        cout << "\nEnter the 1st edge - > ";
        cin >> u;
        cout << "\nEnter the edge to which " << u << " is connected -> ";
        cin >> v;
        adj_matrix[u][v] = 1;
    }
    return adj_matrix;
}
void print_adjacency_matrix(vector<vector<int>> v)
{
    for (const vector<int> &row : v)
    {
        for (int element : row)
        {
            cout << element << ' ';
        }
        cout << endl;
    }
}
int main()
{
    Graph g;
    // directed input
    // g.add_edge(0, 1, 5, 1);
    // g.add_edge(1, 2, 8, 1);
    // g.add_edge(0, 2, 10, 1);
    // cout << endl;
    // g.print_list();
    // undirected input
    // g.add_edge(0, 1, 5, 0);
    // g.add_edge(1, 2, 8, 0);
    // g.add_edge(0, 2, 10, 0);
    // cout << endl;
    // g.print_list();

    // vector<vector<int>> adj_matrix = create_adjacency_matrix(n, e);
    // print_matrix(adj_matrix);
    // n -> number of nodes in graph
    // int n = 5;
    // g.add_edge(0, 1, 0);
    // g.add_edge(1, 3, 0);
    // g.add_edge(1, 2, 0);
    // g.add_edge(3, 5, 0);
    // g.add_edge(3, 7, 0);
    // g.add_edge(7, 6, 0);
    // g.add_edge(7, 4, 0);

    // g.print_list();
    // cout << endl
    //      << "BFS traversal -> ";
    // g.bfs(0);
    // cout << endl
    //      << " DFS traversal -> ";
    // unordered_map<int, bool> visited;
    // g.dfs(0, visited);
    // int n = 5;
    // g.add_edge(0, 1, 1);
    // g.add_edge(1, 2, 1);
    // g.add_edge(2, 3, 1);
    // g.add_edge(3, 4, 1);
    // g.add_edge(4, 0, 1);

    // g.print_list_without_weight();
    // cout << endl;

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsVisited;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans = g.check_directed_graph_is_cyclic_or_not(i, visited, dfsVisited, -1);
    //         if (ans == true)
    //             break;
    //     }
    // }

    // if (ans == true)
    //     cout << "Cycle is Present" << endl;
    // else
    //     cout << "Cycle Absent" << endl;
    unordered_map<int, bool> visited;
    stack<int> ans;
    int n = 8;
    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(3, 4, 1);

    g.add_edge(3, 5, 1);
    g.add_edge(4, 6, 1);
    g.add_edge(5, 6, 1);
    g.add_edge(6, 7, 1);
    g.print_list_without_weight();
    cout << endl;

    // for DFS
    cout << "Topological sort using DFS" << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topological_sort_dfs(i, visited, ans);
        }
    }
    while (!ans.empty())
    {

        cout << ans.top() << " ";
        ans.pop();
    }
    
    // For BFS

    vector<int> ans_bfs;
    g.topological_sort_bfs(n, ans_bfs);
    cout << "\nTopological sort using BFS" << endl; // KAHNS Algorithm
    for (auto it : ans_bfs)
    {
        cout << it << " ";
    }

    return 0;
}