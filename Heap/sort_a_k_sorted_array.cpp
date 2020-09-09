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

int main()
{
    int size, arr[100], k;
    cin >>size >> k;
    for (int i=0; i<size; i++)
        cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        minh.push(arr[i]);

        if (minh.size() > k)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
    }

    while (minh.size() > 0) {
        ans.push_back(minh.top());
        minh.pop();
    }

    for (auto x: ans)
        cout << x<< " ";
}