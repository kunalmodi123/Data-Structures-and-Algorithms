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
const int N = 200005;
/****************************************************************/
//Always check for long long


int get(vector<int>& par, int a){
    if(a == par[a]){
        return a;
    }

    return par[a] = get(par, par[a]);
}

void Union(int u, int v, vector<int>& par, vector<int>& rank){
    u = get(par, u);
    v = get(par, v);

    if(rank[u] < rank[v])
        par[u] = v;
    else if(rank[v] < rank[u])
        par[v] = u;
    else{
        par[v] = u;
        rank[u]++;
    }
}

struct node{
    int u, v, wt;
    node(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
};

bool comp(node n1, node n2){
    return (n1.wt < n2.wt);
}

void kruskalsAlgo(){
    vector<node> edges;
    vector<pair<int, int>> mst;

    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    
    sort(edges.begin(), edges.end(), comp);

    vector<int> par(N+1);
    vector<int> rank(N+1, 0);
    for(int i=1; i<=n; i++){
        par[i] = i;
    }

    int cost = 0;
    for(auto it: edges){
        if(get(par, it.u) != get(par, it.v)){
            cost += it.wt;
            mst.push_back({it.u, it.v});
            Union(it.u, it.v, par, rank);
        }
    }


    cout << "Cost: " << cost;
    cout << "\nMST edges: \n";
    for(auto it: mst){
        cout << it.first << " - " << it.second << "\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
//    cin >> t;
    while(t--)
        kruskalsAlgo();
}