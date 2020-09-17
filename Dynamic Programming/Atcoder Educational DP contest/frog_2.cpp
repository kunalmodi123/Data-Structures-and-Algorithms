#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 3;
const ll INF = 1e9 + 5;
vector<ll> dp(N, INF);

ll frog_2(int n, int k, ll ht[])
{
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=i+k; j++)
        if(j < n)
            dp[j] = min(dp[j], (dp[i] + abs(ht[j] - ht[i])));
    }

    return dp[n-1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << frog_2(n, k, arr);
}