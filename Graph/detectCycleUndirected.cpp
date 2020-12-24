#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debList(list) for(auto x: list) cout << x << " "; cout << endl

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
/****************************************************************/

vi g[N];

bool dfs(int s, vector<bool>& visited, int parent){
    visited[s] = true;
    for(auto v: g[s]){
        if(!visited[v]){
            if(dfs(v, visited, s))
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}

void solve(){
    int m, n;
    cin >> n >> m;
    igraph(n, m, false);

    vector<bool> visited(n+1, false);

    int f=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, visited, -1))
                f = 1;
        }
    }

    if(f)
        cout << "YES";
    else cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
  //  cin >> t;
    while(t--)
        solve();
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void igraph(int n, int m, bool directed)
{
    int i, u, v;
    while (m--){
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        if(!directed)
            g[v].push_back(u);
    }
}