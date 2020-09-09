#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size, arr[100], k;
    cin >>size >> k;
    for (int i=0; i<size; i++)
        cin >> arr[i];

    priority_queue<int> maxh;

    for (int i = 0; i < size; i++)
    {
        maxh.push(arr[i]);

        if (maxh.size() > k)
            maxh.pop();
    }

    cout << maxh.top();
}