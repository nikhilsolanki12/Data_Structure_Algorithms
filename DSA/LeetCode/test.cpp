
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform DFS on the tree
void dfs(int node, vector<vector<int>> &adjList, vector<long long> &maxWeight, bool visited[])
{
    visited[node] = true;

    // Iterate through neighbors of the current node
    for (auto neighbor : adjList[node])
    {
        int neighborNode = neighbor[0];
        long long edgeWeight = neighbor[1];

        // Skip visited neighbors
        if (visited[neighborNode])
        {
            continue;
        }

        // Update maxWeight for the neighbor based on the current max and edge weight
        maxWeight[neighborNode] = max(maxWeight[neighborNode], max(maxWeight[node], edgeWeight));

        // Recursively explore the neighbor node
        dfs(neighborNode, adjList, maxWeight, visited);
    }
}

long long maxEdgeSum(int n, vector<vector<int>> &edges)
{
    // Build the adjacency list to represent the tree
    vector<vector<int>> adjList(n + 1);
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // Undirected edge, add connection for both nodes
    }

    // Array to store the maximum weight seen on the path to each node
    vector<long long> maxWeight(n + 1, 0);

    // Visited array to avoid cycles during DFS
    bool visited[n + 1] = {false};

    // Start DFS from any node (tree is connected)
    dfs(1, adjList, maxWeight, visited);

    // Sum the maximum weight for all nodes (excluding root node 0)
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += maxWeight[i];
    }

    return sum;
}

// For testing the function
int main()
{
    int n1 = 3;
    vector<vector<int>> edges1 = {{1, 2, 2}, {1, 3, 4}};
    cout << "Output for test case 1: " << maxEdgeSum(n1, edges1) << endl; // Output should be 10

    int n2 = 4;
    vector<vector<int>> edges2 = {{1, 2, 1}, {2, 4, 3}, {1, 3, 3}};
    cout << "Output for test case 2: " << maxEdgeSum(n2, edges2) << endl; // Output should be 16

    return 0;
}
