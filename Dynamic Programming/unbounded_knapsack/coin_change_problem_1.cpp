#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int coinChangeWays(int coin[], int n, int sum)
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
            if (coin[i - 1] <= j)
                t[i][j] = (t[i - 1][j] + t[i][j - coin[i - 1]]); //Applying count of subset sum & unbounded knapsack altogether
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n = 4, sum = 10;
    int coin[] = {1, 3, 5, 7};

    cout << coinChangeWays(coin, n, sum) << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}