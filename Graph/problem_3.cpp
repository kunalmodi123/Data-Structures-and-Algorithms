/*
Problem 3:
Detect cycle in a Undirected graph
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

int dfsUtil(int u, vector<bool> &visited, int parent){
    visited[u] = true;
    for (auto v : g[u]){
        //if (visited[v] && v != parent) // My solution line
        //  return 1;
        if (!visited[v]){
            if (dfsUtil(v, visited, u) == 1)
                return 1;
        }
        else if (v != parent) // gfg's solution line
            return 1;
    }
    return 0;
}

int dfsCycle(){
    vector<bool> visited(N, false);
    int ans;
    ans = dfsUtil(0, visited, -1);
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);

    int n, m, u, v;
    cout << "Enter no. of nodes and edges: ";
    cin >> n >> m;

    while (m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << dfsCycle();
}