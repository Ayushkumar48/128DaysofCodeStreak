#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>
class Graph {
   public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if (direction) {
            adjList[v].push_back(u);
        }
    }
    void topoSortBFS() {
        queue<T> q;
        unordered_map<int, int> inDegree;
        for (auto it : adjList) {
            for (auto i : it.second) {
                inDegree[i]++;
            }
        }
        for (auto it : adjList) {
            if (inDegree[it.first] == 0) {
                q.push(it.first);
            }
        }
        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";
            for (auto it : adjList[frontNode]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }
    void shortestPathBFS(T src, T dest, vector<T> &pathToFollow) {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();
            for (auto it : adjList[frontNode]) {
                if (!visited[it]) {
                    q.push(it);
                    parent[it] = frontNode;
                    visited[it] = true;
                }
            }
        }
        while (dest != -1) {
            pathToFollow.push_back(dest);
            dest = parent[dest];
        }
        reverse(pathToFollow.begin(), pathToFollow.end());
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 5, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(0, 6, 1);
    g.addEdge(6, 3, 1);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    vector<int> pathToFollow;
    g.shortestPathBFS(0, 3, pathToFollow);
    for (auto it : pathToFollow) {
        cout << it << " -> ";
    }

    return 0;
}