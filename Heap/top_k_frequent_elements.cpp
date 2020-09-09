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
    int size, arr[100], k;
    cin >>size >> k;
    unordered_map<int, int> mp;
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }


    priority_queue<pi, vector<pi>, greater<pi>> minh;

    for (auto x: mp)
    {
        minh.push({ x.second, x.first });

        if (minh.size() > k)
            minh.pop();
    }

    while (minh.size() > 0) {
        cout << minh.top().second << " ";
        minh.pop();
    }
}