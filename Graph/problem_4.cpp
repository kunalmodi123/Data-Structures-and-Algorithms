#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

bool DFSrec(int u, vector<bool> &visited, vector<bool> &recSt)
{
    visited[u] = true;
    recSt[u] = true;

    for (auto v : g[u])
    {
        if (!visited[v] && DFSrec(v, visited, recSt);)
            return true;
        else if (recSt[u] == true)
            return true;
    }

    recSt[u] = false;
    return false;
}

bool detectCycle(int m)
{
    vector<bool> visited(N, false);
    vector<bool> recSt(N, false);

    for (int i = 0; i < m; i++)
    {
        if (!visited[i])
        {
            if (DFSrec(i, visited, recSt))
                return true;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n, m, u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    if (detectCycle(n))
        cout << "\nThere is a cycle";
    else
        cout << "\nNo Cycle";
}