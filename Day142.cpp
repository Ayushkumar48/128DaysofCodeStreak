// Different cycle detection methods, majorly - undirected and directed.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;
    unordered_map<T, bool> visited;
    void addEdge(T a, T b, bool direction)
    {
        adjList[a].push_back(b);
        if (!direction)
        {
            adjList[b].push_back(a);
        }
    }
    void BFS(T src)
    {
        queue<T> q;
        q.push(src);
        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            if (!visited[frontNode])
            {
                cout << frontNode << " ";
                visited[frontNode] = true;
                for (auto it : adjList[frontNode])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                    }
                }
            }
        }
    }
    void DFS(T src)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto it : adjList[src])
        {
            if (!visited[it])
            {
                visited[it] = true;
                DFS(it);
            }
        }
    }
    void printAdjList()
    {
        for (auto it : adjList)
        {
            cout << it.first << "-> ";
            for (auto i : it.second)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    // Undirected Graph
    bool cycleUndirectedGraphBFS(T src)
    {
        queue<T> q;
        unordered_map<T, T> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            for (auto it : adjList[frontNode])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                    parent[it] = frontNode;
                }
                else
                {
                    if (it != parent[frontNode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool cycleUndirectedGraphDFS(T src, T parent)
    {
        visited[src] = true;
        for (auto it : adjList[src])
        {
            if (!visited[it])
            {
                bool ans = cycleUndirectedGraphDFS(it, src);
                if (ans)
                    return true;
            }
            else
            {
                if (it != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Directed Graph
    bool cycleDirectedGraphDFS(T src, unordered_map<T, bool> &track)
    {
        visited[src] = true;
        track[src] = true;
        for (auto it : adjList[src])
        {
            if (!visited[it])
            {
                bool ans = cycleDirectedGraphDFS(it, track);
                if (ans)
                    return true;
            }
            else
            {
                if (track[it])
                    return true;
            }
        }
        track[src] = false;
        return false;
    }
};
int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 1);
    g.addEdge('a', 'c', 1);
    g.addEdge('b', 'c', 1);
    g.addEdge('b', 'd', 1);
    g.addEdge('b', 'e', 1);
    g.addEdge('c', 'd', 1);
    g.addEdge('e', 'g', 1);
    g.addEdge('e', 'f', 1);
    g.addEdge('c', 'a', 1);
    // g.DFS('a');
    // g/BFS('a');
    // g.printAdjList();
    cout << g.cycleUndirectedGraphDFS('a', '0') << "\n";
    cout << g.cycleUndirectedGraphBFS('a') << "\n";
    unordered_map<char, bool> track;
    bool isCycle = g.cycleDirectedGraphDFS('a', track);
    if (isCycle)
        cout << "Cycle Present";
    else
        cout << "Cycle Not Present";
    return 0;
}