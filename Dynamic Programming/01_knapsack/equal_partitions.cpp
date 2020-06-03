#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

bool subsetSum(int arr[], int n, int sum)
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

bool equalPartitions(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) // We calculate the total sum of array elements
        sum += arr[i];

    if (sum % 2 != 0) // if sum is odd, it cannot be splitted into two partitions
        return false; // so, return false
    else              // If sum is even, then just a find a subset with sum = sum/2,  the other part will be same
        return subsetSum(arr, n, sum / 2);
}

int main()
{
    int n = 5;
    int arr[] = {4, 7, 5, 3, 8};

    bool h = equalPartitions(arr, n);

    if (h)
        cout << "YES";
    else
        cout << "NO";
}