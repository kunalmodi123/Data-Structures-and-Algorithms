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

int ht[100005], stored[100005];
bool is_computed[100005];

int frog_1(int n){
    if(n == 1)
        return 0;
    
    if(is_computed[n]) return stored[n];

    int curr_ans = 1000000009;
    curr_ans = min(curr_ans, frog_1(n-1) + abs(ht[n] - ht[n-1]));
    if(n-2 >= 1) curr_ans = min(curr_ans, frog_1(n-2) + abs(ht[n] - ht[n-2]));

    stored[n] = curr_ans;
    is_computed[n] = true;
    return curr_ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ht[i];

    cout << frog_1(n);
}