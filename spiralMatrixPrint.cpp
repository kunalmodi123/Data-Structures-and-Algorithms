#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
const int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n, 0)>);
    int l=n-1; int k=0;
    int cnt=1;
    int alt=1;

    for(int i=k; i<=l; i++){
        if(alt == 1){
            grid[k][i] = cnt++;
            alt *= -1;
        }
        else{
            grid[i][k] = cnt++;
            alt *= -1;
        }
        
        if(i == l){
            if(alt == -1){
                i = k+1;
                k = 
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
   // cin >> t;
    while(t--)
        solve();
}