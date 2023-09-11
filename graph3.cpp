#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
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
};

// class Graph {
// public:
//  unordered_map<int, list<pair<int,int> > > adjList;

//  void addEdge(int u, int v,int weight, bool direction) {
//    //direction = 0 -> undirected graph
//    //direction = 1 -> directed graph
//    //create an edge from u to v
//    adjList[u].push_back({v,weight});
//    if(direction == 0)
//    {
//      //undirected edge
//      //create an edge from v to u
//      adjList[v].push_back({u,weight});
//    }
//  }

//  void printAdjacencyList() {
//    for(auto node: adjList) {
//      cout << node.first << "-> " ;
//      for(auto neighbour: node.second) {
//        cout <<"("<<neighbour.first<<","<<neighbour.second<<"), ";
//      }
//      cout << endl;
//    }
//  }

// };

int main()
{
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 0, 1);

    g.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.check_directed_graph_is_cycle_or_not(i, visited, dfsVisited,-1);
            if (ans == true)
                break;
        }
    }

    if (ans == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;
    // Graph<int> g;
    // // n -> number of nodes in graph
    // int n = 5;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 4, 0);
    // // g.addEdge(4, 0, 0);

    // g.printAdjacencyList();
    // cout << endl;
    // g.bfs(0);
    // cout << endl;
    // // g.dfs(0);
    // unordered_map<int, bool> visited;
    // bool ans_bfs = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans_bfs = g.check_cyclic_using_bfs(i, visited);
    //         if (ans_bfs == true)
    //         {

    //             break;
    //         }
    //     }
    // }
    // if (ans_bfs == true)
    // {
    //     cout << "yes cycle present using bfs" << endl;
    // }
    // else
    // {
    //     cout << "No cycle present using bfs" << endl;
    // }
    // bool ans_dfs = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans_dfs = g.check_cyclic_using_dfs(i, visited, -1);
    //         if (ans_dfs == true)
    //         {

    //             break;
    //         }
    //     }
    // }
    // if (ans_dfs == true)
    // {
    //     cout << "yes cycle present using dfs" << endl;
    // }
    // else
    // {
    //     cout << "No cycle present using dfs" << endl;
    // }
    // run a loop for all nodes
    // cout << "Printing BFS Traversal: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.bfs(i, visited);
    //     }
    // }
    // cout << endl
    //      << "Printing DFS Traversal: " << endl;
    // unordered_map<int, bool> visited2;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited2[i])
    //     {
    //         g.dfs(i, visited2);
    //     }
    // }

    // Graph<char> g;
    // g.addEdge('a','b', 0);
    // g.addEdge('b', 'c', 0);
    // g.addEdge('a', 'c', 0);
    // g.printAdjacencyList();

    // directed input
    // g.addEdge(srcNode, destNode, weight, direction);
    //  g.addEdge(0,1,5,1);
    //  g.addEdge(1,2,8,1);
    //  g.addEdge(0,2,6,1);
    //  cout << endl;
    //  g.printAdjacencyList();

    // undirected edge input
    //  g.addEdge(0,1,0);
    //  g.addEdge(1,2,0);
    //  g.addEdge(0,2,0);
    //  cout << endl;
    //  g.printAdjacencyList();

    // int n;
    // cout << "Enter the number of nodes: " << endl;
    // cin >> n;

    // int e;
    // cout << "Enter the number of edges: " << endl;
    // cin >> e;

    // //undirected graph

    // int n;
    // cout << "Enter the number of nodes: " << endl;
    // cin >> n;

    // vector<vector<int> > adj(n, vector<int>(n,0));

    // int e;
    // cout << "Enter the number of edges: " << endl;
    // cin >> e;

    // for(int i=0; i<e; i ++) {
    //  int u,v;
    //  cin >> u >> v;
    //  //mark 1
    //  adj[u][v] = 1;
    // }

    // //printing
    // for(int i=0; i<n; i++) {
    //  for(int j =0; j<n; j++) {
    //    cout << adj[i][j] << " ";
    //  }
    //  cout << endl;
    // }
    // Graph<int> directed;
    // // n -> number of nodes in graph
    // // int n = 5;
    // directed.addEdge(0, 1, 1);
    // directed.addEdge(1, 2, 1);
    // directed.addEdge(2, 3, 1);
    // directed.addEdge(3, 4, 1);
    // directed.addEdge(4, 0, 1);

    // directed.printAdjacencyList();
    // cout << endl;
    // directed.bfs(0);
    // cout << endl;
    // unordered_map<int, bool> visiteed;
    // unordered_map<int, bool> dfs_visiteed;
    // bool ans_dfs_directed = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans_dfs_directed = g.check_directed_graph_is_cycle_or_not(i, visited, dfs_visiteed, -1);
    //         if (ans_dfs_directed == true)
    //         {

    //             break;
    //         }
    //     }
    // }
    // if (ans_dfs_directed == true)
    // {
    //     cout << "yes cycle present using dfs in directed" << endl;
    // }
    // else
    // {
    //     cout << "No cycle present using dfs in directed" << endl;
    // }
    return 0;
}