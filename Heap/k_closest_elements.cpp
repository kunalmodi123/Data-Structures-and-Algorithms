#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size, arr[100], k, num;
    cin >>size >> k >> num;
    for (int i=0; i<size; i++)
        cin >> arr[i];

    priority_queue<pair<int, int>> maxh;

    for (int i = 0; i < size; i++)
    {
        maxh.push({ abs(arr[i] - num), arr[i] });

        if (maxh.size() > k)
            maxh.pop();
    }

    while (maxh.size() > 0)
    {
        cout << maxh.top().second;
        maxh.pop();
    }
}
