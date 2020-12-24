#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
const int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int m=0, k = 0;

    for(int i=0; i<n; i++){
        if(a[i] > a[(i+1)%n]){
            m++;
            if(m > 1) {
                cout << -1;
                return;
            }
            k=i+1;
        }
    }
    cout << n-k;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}