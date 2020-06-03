#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int countSubsetSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    int n = 6, sum = 10;
    int arr[] = {2, 3, 5, 6, 8, 10};

    int h = countSubsetSum(arr, n, sum);

    cout << "count: " << h << endl
         << endl;

    cout << "  ";
    for (int i = 0; i <= sum; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < n + 1; i++)
    {
        cout << i << " ";
        for (int j = 0; j < sum + 1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}