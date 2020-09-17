#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 3;
vector<ll> dp(N);    

ll frog(int n, ll ht[])
{
    dp[1] = 0;
    dp[2] = abs(ht[1] - ht[0]);
    for(int i = 3; i<=n; i++)
    {
        dp[i] = min((dp[i-1] + abs(ht[i-1] - ht[i-2])),(dp[i-2] + abs(ht[i-1] - ht[i-3])));
    }

    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << frog(n, arr);

}