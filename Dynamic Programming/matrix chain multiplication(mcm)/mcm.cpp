#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int mcmRec(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = mcmRec(arr, i, k) + mcmRec(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, tempAns);
    }

    return ans;
}

int mcmMemo(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = mcmMemo(arr, i, k) + mcmMemo(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, tempAns);
    }

    t[i][j] = ans;
    return t[i][j];
}

int main()
{
    memset(t, -1, sizeof(t));
    int arr[] = {40, 20, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << mcmMemo(arr, 1, n - 1);
}
