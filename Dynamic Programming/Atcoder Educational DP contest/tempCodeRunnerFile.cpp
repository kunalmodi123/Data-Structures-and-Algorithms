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

int ht[100005], stored[100005];
bool is_computed[100005];

int frog_2(int n, int k){
    if(n == 1)
        return 0;
    
    if(is_computed[n]) return stored[n];

    int curr_ans = 1000000009;
    for(int i=1; i<=k; i++)
        if(n-i >= 0) curr_ans = min(curr_ans, frog_2(n-i, k) + abs(ht[n] - ht[n-i]));

    stored[n] = curr_ans;
    is_computed[n] = true;
    return curr_ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ht[i];

    cout << frog_2(n, k);
}