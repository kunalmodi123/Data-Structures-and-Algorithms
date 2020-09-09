#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define INPUT freopen("input.txt", "r", stdin)
#define MOD 1000000007

typedef pair<int, int> pi;

int main()
{
    int size, arr[100];
    cin >>size;
    unordered_map<int, int> mp;
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    priority_queue<pi> maxh;

    for (auto x: mp)
        maxh.push({ x.second, x.first });

    while (maxh.size() > 0) {
        int freq = maxh.top().first;
        int ele = maxh.top().second;
        for (int i=1; i<=freq; i++)
            cout << ele << " ";
        maxh.pop();
    }
}