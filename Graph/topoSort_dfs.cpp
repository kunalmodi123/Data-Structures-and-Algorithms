#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> g[N];
vector<int> topoSort;
vector<bool> vis(N, false);

void dfs(int s, vector<bool>& vis){
    vis[s] = true;
    for(auto v: g[s]){
        if(!vis[v]){
            dfs(v, vis);
        }
    }
    topoSort.push_back(s);
}

void solve(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i, vis);
    }
    
    reverse(topoSort.begin(), topoSort.end());
    cout << "Topological Sort(using dfs): \n";
    for(auto x : topoSort){
        cout << x << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
}