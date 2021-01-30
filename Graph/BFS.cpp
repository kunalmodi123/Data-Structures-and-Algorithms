#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

void BFS(int u){
    vector<bool> visited(N, 0);
    cout << "BFS is : \n";

    queue<int> q;
    visited[u] = 1;
    q.push(u);

    while (!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto v : g[node]){
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BFS(4);
    cout << "\n";
    BFS(3);
}