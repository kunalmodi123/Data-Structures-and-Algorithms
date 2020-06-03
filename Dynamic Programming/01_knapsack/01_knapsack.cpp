#include <bits/stdc++.h>
using namespace std;

int t[1002][102];

int knapsackRec(int val[], int wt[], int w, int n) // Recursive solution
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] <= w)
        return max(val[n - 1] + knapsackRec(val, wt, w - wt[n - 1], n - 1), knapsackRec(val, wt, w, n - 1));
    else
        return knapsackRec(val, wt, w, n - 1);
}

int knapsackdpMemo(int val[], int wt[], int w, int n) // Memoization
{
    if (n == 0 || w == 0)
        return 0;
    if (t[w][n] != -1)
        return t[w][n];

    if (wt[n - 1] <= w)
        t[w][n] = max(val[n - 1] + knapsackdpMemo(val, wt, w - wt[n - 1], n - 1), knapsackdpMemo(val, wt, w, n - 1));
    else
        t[w][n] = knapsackdpMemo(val, wt, w, n - 1);

    return t[w][n];
}

int knapsackdpTab(int val[], int wt[], int w, int n) // Tabulation
{
    for (int i = 0; i < w + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < w + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (wt[j - 1] <= i)
                t[i][j] = max(val[j - 1] + t[i - wt[j - 1]][j - 1], t[i][j - 1]);
            else
                t[i][j] = t[i][j - 1];
        }
    }

    return t[w][n];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n = 4, w = 80;
    int wt[] = {10, 20, 30, 40};
    int val[] = {60, 100, 120, 240};

    cout << knapsackdpMemo(val, wt, w, n) << endl;
    for (int i = 0; i < w + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << t[i][j] << "\t";
        cout << endl;
    }
}

/*
Important variations of 0/1 knapsack problem:
1. Subset sum problem
2. Equal sum partition
3. Count of subset sum
4. Minimum subset sum diff.
5. Target sum (leetcode)
6. Number of subset with given diff.
*/