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

    vector<int> inDeg(n+1, 0); // number of incoming edges in each node
    igraph(1, 2, inDeg);
    igraph(1, 3, inDeg);
    igraph(2, 4, inDeg);
    igraph(2, 6, inDeg);
    igraph(5, 3, inDeg);

    queue<int> q;
    for(int i=1; i<=n; i++){
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
    int n = 6;
    topologicalSort(n);
}

int main(){

    int t = 1;
   // cin >> t;
    while(t--)
        solve();
}