// Today I learned two graphs traversals - Breadth First Search (BFS) and Depth First Search (DFS).
// Out of them BFS is very similar to level order traversal in Trees.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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
    void BFS(T src)
    {
        unordered_map<T, bool> ump;
        queue<T> q;
        q.push(src);
        ump[src] = true;
        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            for (auto neighbour : adjList[frontNode])
            {
                T data = neighbour.first;
                if (!ump[data])
                {
                    q.push(data);
                    ump[data] = true;
                }
            }
        }
    }
    void DFS(T src)
    {
        unordered_map<T, bool> ump;
        ump[src] = true;
        cout << src << " ";
        for (auto it : adjList[src])
        {
            T data = it.first;
            if (!ump[data])
            {
                DFS(data);
            }
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
    g.BFS(1);
    cout << "\n";
    g.DFS(1);
    return 0;
}