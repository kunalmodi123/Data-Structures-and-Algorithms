// count ways to reach nth stair (can take 1 or 2 steps at a time)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> dp(N+1, -1);
int nthStair(int n)
{
    if (n==1)
        dp[n] = 1;
    if(n==2)
        dp[n] = 2;

    if((dp[n] == -1))
        dp[n] = nthStair(n-1) + nthStair(n-2);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << nthStair(n);
}