#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

void DFSutility(int u, vector<bool> &visited)
{
    visited[u] = 1;
    cout << u << " ";
    for (auto v : g[u])
    {
        if (visited[v])
            continue;
        else
            DFSutility(v, visited);
    }
}

void DFS(int u)
{
    vector<bool> visited(N, 0);
    cout << "DFS is : \n";

    DFSutility(u, visited);
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    DFS(4);
    cout << "\n";
    DFS(3);
}