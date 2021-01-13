/*
Topological Sort using BFS - Kahn's Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
const int mod = 1e9+7;
const int N = 2e5;

vector<int> g[N];

void igraph(int u, int v, vector<int>& inDeg){
        g[u].push_back(v);
        inDeg[v]++;
}

void topologicalSort(int n){

    vector<int> inDeg(n, 0); // number of incoming edges in each node
    igraph(0, 2, inDeg);
    igraph(0, 3, inDeg);
    igraph(1, 3, inDeg);
    igraph(1, 4, inDeg);
    igraph(2, 3, inDeg);

    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDeg[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto x: g[node]){
            inDeg[x]--;
            if(inDeg[x] == 0) // if the node has no dependancy (inDegree will become 0)
                q.push(x);
        }
    }
}

void solve(){
    int n = 5;
    topologicalSort(n);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
   // cin >> t;
    while(t--)
        solve();
}