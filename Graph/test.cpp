#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

void addEdgeInUndirected(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void addEdgeInDirected(int u, int v)
{
    g[u].push_back(v);
}

void BFS(int u)
{

    vector<bool> visited(N, 0);
    cout << "BFS for source " << u << " is : \n";

    queue<int> q;
    visited[u] = 1;
    q.push(u);

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto v : g[node])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<string> v;
    v.push_back("kunal");
    v.push_back("modi");

    vector<string>::iterator it = v.begin();
    cout << (*it)[3];
}