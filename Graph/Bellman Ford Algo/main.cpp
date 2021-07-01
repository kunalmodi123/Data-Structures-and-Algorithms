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

struct node{
    int u, v, wt;
    node(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
};

// accordingly written to satisfy 0 based indexing
void bellmanFord(){
    vector<node> edges;

    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    int inf = 100000008;
    vector<int> dist(n, inf);
    dist[0] = 0;

    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            if(dist[it.v] > dist[it.u] + it.wt)
                dist[it.v] = dist[it.u] + it.wt;
        }
    }

    int fl = 0;
    for(auto it: edges){
        if(dist[it.v] > dist[it.u] + it.wt){
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if(!fl){
        for(int i=0; i<n; i++)
            cout << dist[i] << " ";
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
        bellmanFord();
}