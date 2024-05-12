// Topological Sort
#include <bits/stdc++.h>

#include <iostream>
using namespace std;
template <typename T>
class Graph {
   public:
    unordered_map<T, list<T>> adjList;
    unordered_map<T, bool> visited;
    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if (!direction) {
            adjList[v].push_back(u);
        }
    }
    void printAdjList() {
        for (auto it : adjList) {
            cout << it.first << " -> ";
            for (auto i : it.second) {
                cout << i << ", ";
            }
            cout << "\n";
        }
    }
    void topoSortDFS(T src, stack<T>& st) {
        visited[src] = true;
        for (auto it : adjList[src]) {
            if (!visited[it]) {
                topoSortDFS(it, st);
            }
        }
        st.push(src);
    }
};
int main() {
    Graph<int> g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.printAdjList();
    stack<int> st;
    int nodes = 8;
    for (int i = 0; i < nodes; i++) {
        if (!g.visited[i]) {
            g.topoSortDFS(1, st);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

// LeetCode
// 207. Course Schedule
class Graph {
   public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v) { adjList[u].push_back(v); }
    bool topoSortDFS(int src, unordered_map<int, bool>& visited,
                     unordered_map<int, bool>& track) {
        visited[src] = true;
        track[src] = true;
        for (auto it : adjList[src]) {
            if (visited[it] && track[it]) {
                return false;
            }
            if (!visited[it]) {
                if (!topoSortDFS(it, visited, track)) {
                    return false;
                }
            }
        }
        track[src] = false;
        return true;
    }
};
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        Graph g;
        for (auto it : pr) {
            g.addEdge(it[0], it[1]);
        }
        unordered_map<int, bool> track;
        unordered_map<int, bool> visited;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!g.topoSortDFS(i, visited, track)) {
                    return false;
                }
            }
        }
        return true;
    }
};