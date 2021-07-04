//Trees - dfs, bfs, subtree size, height parent array, level array, kth parent, lca and problems based on it

#include<bits/stdc++.h>
using namespace std;

//dfs
//here we dont need a visited array cause it trees dont have cycles
// we will have a parent parameter
const int N = (int)(1e5 + 3);
vector<int> adj[N];
void dfs(int node, int par){
    //** parent[node] = par; // this line will give us an array with parents of all node
    cout << node << " ";
    for(auto x: adj[node]){
        if(x != par)
            dfs(x, node);
    }
}
//=================================================================================================================//

//bfs for tree
void bfs(int s){
    queue<pair<int, int>> q;
    q.push({s, -1});
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        cout << node << " ";
        for(auto it: adj[node]){
            if(it != par)
                q.push({it, node});
        }
    }
}
//=======================================================================================================//
//height of the tree
int height = 0;

void dfs_height(int node, int par, int level){
    height = max(height, level);
    for(auto it: adj[node]){
        if(it != par)
            dfs_height(it, node, level + 1);
    }
}

void solve1(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_height(1, -1, 1);
    cout << "height: " << height << "\n";
}
//==========================================================================================================//

//subtree size

void dfs_sub(int node, int par, vector<int>& subT){
    subT[node] = 1;
    for(auto it: adj[node]){
        if(it != par){
            dfs_sub(it, node, subT);
            // after this dfs is over, subtree size of node weill be calculated
            subT[node] += subT[it];
        }
    }
}

void solve2(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<int> subT(n+1);
    dfs_sub(1, -1, subT);
    cout << "\nsubtree size of all nodes: \n";
    for(auto x: subT){
        cout << x << " ";
    }
    cout << endl;
}

//==============================================================================================================//

// codeforces 1336 A - Linova and Kingdom
// https://codeforces.com/problemset/problem/1336/A

/*
int subtree[100005], level[100005]; 
vector<int> contri; 
void dfs(int node, int par, int lev) {
    subtree[node] = 1; 
    level[node] = lev; 
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node, lev + 1); 
            // after the dfs of it is over, can i say that the subtree size of it would have been computed
            subtree[node] += subtree[it]; 
        }
    }
}

void solve() {
    // input 
    dfs(1,-1, 1); 
    for(int i = 1;i<=n;i++) {
        contri.push_back(level[node] - subtree[node]); 
    }
    sort(contri.begin(), contri.end()); 
    reverse(contri.begin(), contri.end()); 
    int ans = 0;
    for(int i = 0;i<k;i++) {
        ans += contri[i]; 
    }
    cout << ans; 
}
*/
void dfs_3(int node, int par, int level, vector<int>& ans, vector<int>& sub){
    sub[node] = 1;
    
    for(auto it: adj[node]){
        if(it != par){
            dfs_3(it, node, level + 1, ans, sub);
            sub[node] += sub[it];
        }
    }
    ans[node] = level - sub[node];
}

void solve3(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n+1);
    vector<int> sub(n+1);
    dfs_3(1, -1, 1, ans, sub);
    sort(ans.rbegin(), ans.rend());
    long long sum=0;
    for(int i=0; i<k; i++){
        sum += ans[i];
    }

     cout << sum << "\n";
}
//==============================================================================================================//
/*
int parent[100004][18];
int level[100005]; 
void dfs(int node, int par, int lev) {
    
    level[node] = lev;
    parent[node][0]= par; 
    for(int i = 0;i<17;i++) {
        parent[node][i+1] = parent[parent[node][i]][i]; 
    }
    
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node, lev + 1); 
        }
    }
}


int findKthParent(int node, int k) {
    for(int i = 0;i<=log2(k);i++) {
        if(k & (1<<i)) {
            node = parent[node][i]; 
        }
    }
    return node; 
}

int lca(int u, int v) {
    if(level[v] < level[u]) swap(u, v); 
    
    int dist = level[v] - level[u]; 
    v = findKthParent(v, dist); 
    
    if(u==v) return u; 
    
    for(int i = 17;i>=0;i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i]; 
            v = parent[v][i]; 
        }
    }
    
    return parent[u][0]
    
}


int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u,v)]; 
}
*/

int main(){

}
