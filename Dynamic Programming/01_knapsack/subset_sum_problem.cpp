#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

bool subset_sum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    int n = 5, sum = 17;
    int arr[] = {4, 7, 5, 3, 8};

    bool h = subset_sum(arr, n, sum);

    if (h)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n\n";

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}