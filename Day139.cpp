// Today, I learned a new data structure, Graph.
// It is a non-linear data structure made up of vertices(aka nodes) and edges. Edges are lines that connect two vertices in the graph.
// There are two types of representation of graphs:-
// Adjacency Matrix - It is a way of representing a graph as a matrix of boolean (0’s and 1’s).
// Adjacency List - An array of Lists is also used to store edges between two vertices.
// Major Types of graphs -
// Undirected Graphs: A graph in which edges have no direction.
// Directed Graphs: A graph in which edges have a direction.
// Weighted Graphs: A graph in which edges have weights or costs associated with them.
// Unweighted Graphs: A graph in which edges have no weights or costs associated with them.

// Code given here is only based on adjacency list. Adjacency matrix code uses a 2D boolean matrix, which is very simple so I didn't wrote it.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class GraphVertex
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        // direction -> 0 -> undirected
        // direction -> 1 -> directed
        if (direction == 1)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto it : adjList)
        {
            cout << it.first << " -> {";
            for (auto neighbour : it.second)
            {
                cout << neighbour << ", ";
            }
            cout << "}" << endl;
        }
    }
};
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;
    void addEdge(T u, T v, bool direction, int weight)
    {
        if (direction == 1)
        {
            adjList[u].push_back({v, weight});
        }
        else
        {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1, 2, 1, 5);
    g.addEdge(2, 3, 1, 6);
    g.addEdge(1, 7, 1, 9);
    g.addEdge(3, 5, 1, 46);
    // g.printAdjList();
    return 0;
}