#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
vector<int> adj[100005];
bool vis[100005];
stack<int> stk;
vector<int> cycle;
void dfs(int node, int par, int& f){
    vis[node] = true;
    stk.push(node);
    for(auto it: adj[node]){
        if(f == 1) continue; // to stop and not colecting other cycles since we  got one
        if(!vis[it])
            dfs(it, node, f);
        else if(it != par){
            
            while(!stk.empty() and stk.top() != it){
                cycle.push_back(stk.top());
                stk.pop();
            }
            cycle.push_back(it);
            f = 1; // to stop and not collecting any further cycles
            return;
        }
    }
    if(!stk.empty()) // to avoid segmentation fault
        stk.pop();
} 
 
void _dfs(int n){
    int f=0;
    for(int i=1; i <=n ;i++){
        if(f == 1) break;
        if(!vis[i])
            dfs(i, -1, f);
    }
}
 
signed main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    _dfs(n);
    if(cycle.size() == 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cycle.push_back(cycle[0]);
    cout << cycle.size() << "\n";
    for(auto x: cycle){
        cout << x << " ";
    }
    cout << endl;
    
}