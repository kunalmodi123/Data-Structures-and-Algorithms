/*ktgm*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debList(list) for(auto x: list) cout << x << " "; cout << endl
#define fo(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int mpow(int base, int exp);
void igraph(int n, int m, bool directed);

const int mod = 1e9+7;
const int N = 2e5;
# define INF 0x3f3f3f3f
/****************************************************************/

vector<pair<int, int>> g[N];

// based on 0 based indexing (node initial value is 0)
void dijkstraAlgo(int V, int src){ // O((V+E)logV) ~ O(ElogV) time
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INF); 

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){ // runs in V time
        int u = pq.top().second; 
        int w = pq.top().first;
        pq.pop();

        for(auto x: g[u]){ // runs in E time overall
            int v = x.first;
            int weight = x.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // logV time
            }
        }
    }

   // printing distance from source to all vertices
   cout << "Distance of all vertices from source "<< src  << "\n";
    for(int i=0; i<V; i++)
        cout << i << "  -  " << dist[i] << "\n";
}

void solve(){
    int m, n;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int src = 1;
    dijkstraAlgo(n, src);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
 //   cin >> t;
    while(t--)
        solve();
}