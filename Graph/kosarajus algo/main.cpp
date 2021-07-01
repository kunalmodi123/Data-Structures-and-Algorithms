/*ktgm*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debList(list) for(auto x: list) cout << x << " "; cout << endl
#define rep(i, x, n) for (int i = x; i < n; i++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))

const int mod = 1000000007;
const int N = 100005;
/****************************************************************/
//Always check for long long

// this algo is used to find strongly connected components

vector<int> adj[N];

void topoSort(int node, stack<int>& st, vector<int>& vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it])
            topoSort(it, st, vis);
    }
    st.push(node);
}

void revDfs(int node, vector<int>& vis, vector<int> transpose[]){
    cout << node << " ";
    vis[node] = 1;
    for(auto it: transpose[node]){
        if(!vis[it])
            revDfs(it, vis, transpose);
    }
}

void kosarajuAlgo(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!vis[i])
            topoSort(i, st, vis);
    }

    vector<int> transpose[N];
    for(int i=1; i<=n; i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }

    cout << "SCC: \n";
    while(!st.empty()){
        int node = st.top();
        st.pop();   
        if(!vis[node]){
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    kosarajuAlgo();
}