#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int lo = 0, hi = k / 2;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int f = mid * (k - mid);
        if (f == k)
        {
            cout << mid << " " << (k - mid);
            return 0;
        }
        else if (f < k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << "No Integers found that follows the criteria mentioned!";
}