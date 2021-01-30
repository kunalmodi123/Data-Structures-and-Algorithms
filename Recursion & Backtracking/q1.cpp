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
/****************************************************************/

vvi g(N);

void patternPrint(string s, int i, int n, string osf){
    if(i == n){
        cout << osf << "\n";
        return;
    }
    
    if((s[i] >= 97 && s[i] <= 122) or (s[i] >= 65 && s[i] <= 90)){
        patternPrint(s, i+1, n, osf + char(tolower(s[i])));
        patternPrint(s, i+1, n, osf + char(toupper(s[i])));
    }
    else patternPrint(s, i+1, n, osf + s[i]);
}

void solve(){
    int m, n;
    string s;
    cin >> s;
    n = s.length();

    patternPrint(s, 0, n, "");

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

void igraph(int n, int m, bool directed = false)
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