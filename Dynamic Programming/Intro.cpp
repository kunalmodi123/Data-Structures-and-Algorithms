#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e6;

vector<ll> memo(N + 1, -1);

ll memoFib(ll n) // memoization solution (Top - Down Approach)
{
    if (memo[n] == -1)
    {
        ll res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = memoFib(n - 1) + memoFib(n - 2);
        memo[n] = res;
    }
    return memo[n];
}

ll tabFib(int n) // tabulation solution (Bottom - Up Approach)
{
    ll f[n + 1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main()
{
    ll n;
    cin >> n;
    cout << memoFib(n) << " ";
    cout << tabFib(n);
}