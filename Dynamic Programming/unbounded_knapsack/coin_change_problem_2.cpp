#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int coinChangeMin(int coin[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++) // Initialization, important
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = INT_MAX - 1;
        }
    }

    for (int j = 1; j < sum + 1; j++) //inializing second row, very important
    {
        if (j % coin[0] == 0)
            t[1][j] = j / coin[0];
        else
            t[1][j] = INT_MAX - 1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - coin[i - 1]]); // + 1 because we are counting
            else                                                       // the coins after we decide to put it
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n = 4, sum = 10;
    int coin[] = {2, 1, 5, 7};

    cout << coinChangeMin(coin, n, sum) << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < sum + 1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
}