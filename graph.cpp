#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjacency_list;

    void add_edge(int u, int v, int weight, bool direction)
    {
        // direction =0 -> undirected graph
        // direction =1 -> directed graph
        adjacency_list[u].push_back({v, weight}); // create an edge for both directed and undirectd graph(i.e 1st edge)
        if (direction == 0)
        {
            adjacency_list[v].push_back({u, weight}); // create an edge from v to u for undirected graph
        }
    }
    void print_adj_list()
    {
        for (auto node : adjacency_list)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)

                cout << "(" << neighbour.first << "," << neighbour.second << ") ,";
            cout << endl;
        }
    }
};

vector<vector<int>> create_adjacency_matrix(int number_of_nodes, int number_of_edges)
{
    vector<vector<int>> adj(number_of_nodes, vector<int>(number_of_nodes, 0));

    /*(n, vector<int>(n, 0)): This is a constructor call that initializes the vector adj with dimensions n by n. Here's how it works:

    vector<int>(n, 0) creates an inner vector of size n with all elements initialized to 0. This inner vector represents a row in the two-dimensional grid.
    The outer vector<vector<int>> then contains n such rows, creating a n by n grid.*/
    for (int i = 0; i < number_of_edges; i++)
    {
        int u, v;
        cout << "Enter the 1st edge adn 2nd edge which are connected ->  ";
        cin >> u >> v;
        adj[u][v] = 1;
    }
    return adj;
}
void print_matrix(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    // cout << "Enter number of node -> ";
    // cin >> n;
    // int e;
    // cout << "\nEnter number of edges -> ";
    // cin >> e;

    Graph g;
    // directed input
    g.add_edge(0, 1, 5, 1);
    g.add_edge(1, 2, 8, 1);
    g.add_edge(0, 2, 10, 1);
    cout << endl;
    g.print_adj_list();
    // undirected input
    // g.add_edge(0, 1, 0);
    // g.add_edge(1, 2, 0);
    // g.add_edge(0, 2, 0);
    // cout << endl;
    // g.print_adj_list();

    // vector<vector<int>> adj_matrix = create_adjacency_matrix(n, e);
    // print_matrix(adj_matrix);
    return 0;
}