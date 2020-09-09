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

typedef pair<int, pair<int, int>> pi;

int main()
{
    int size, arr[100][2], k;
    cin >> size >> k;
    unordered_map<int, pair<int, int>> mp;
    for (int i=0; i<size; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        int ans = pow(arr[i][0], 2) + pow(arr[i][1], 2);
        mp.insert({ ans, { arr[i][0], arr[i][1] } });
    }

    priority_queue<pi> maxh;

    for (auto x: mp)
    {
        maxh.push({ x.first, x.second });

        if (maxh.size() > k)
            maxh.pop();
    }

    while (maxh.size() > 0) {
        cout << maxh.top().second.first << " " << maxh.top().second.second << endl;
        maxh.pop();
    }
}