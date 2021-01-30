/*
Problem 2:
Find shortest distance between the given source vertex with 
all the other vertices in a given graph
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

 // a function with vector as a return type
vector<int> shortestDistance(int u, int n){
    vector<bool> visited(N, 0);
    vector<int> dist(n, 0); // to store the answer
    queue<int> q;
    visited[u] = 1;
    q.push(u);

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (auto v : g[node]){
            if (!visited[v]){
                dist[v] = dist[node] + 1; // Only difference in BFS traversal code
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main(){
    int n, m, u, v;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    cout << "\nConstruct the graph by adding edges from u---v for " << m << " nodes: \n";
    while (m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source;
    cout << "\nEnter the source node: ";
    cin >> source;
    vector<int> ans = shortestDistance(source, n);

    for (auto x : ans)
        cout << x << " ";
}