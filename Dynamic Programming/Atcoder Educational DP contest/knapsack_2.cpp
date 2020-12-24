#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e9 + 1;
vector<vector<ll>> t(N, vector<ll> (101));

ll knapsackdpTab(ll val[], ll wt[], ll w, ll n) // Tabulation
{
    for (int i = 0; i < w + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < w + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (wt[j - 1] <= i)
                t[i][j] = max(val[j - 1] + t[i - wt[j - 1]][j - 1], t[i][j - 1]);
            else
                t[i][j] = t[i][j - 1];
        }
    }

    return t[w][n];
}

int main()
{
    memset(t, -1, sizeof(t));
    ll n, w;
    cin >> n >> w;
    ll wt[n];
    ll val[n];
    for(int i=0; i<n; i++)
        cin >> wt[i] >> val[i];


    cout << knapsackdpTab(val, wt, w, n);
}
