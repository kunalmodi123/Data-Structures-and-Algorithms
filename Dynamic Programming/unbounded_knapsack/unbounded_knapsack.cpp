#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

//The code very similar to the 0/1 knapsack code with only one change to tackle multiple occurences
int unboundedKnapsack(int val[], int wt[], int n, int w)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(t[i - 1][j], val[i - 1] + t[i][j - wt[i - 1]]); //When we choose to take the element
            else                                                              // we change i - 1 to i for multiple occurences
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][w];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n = 4, w = 80;
    int wt[] = {10, 20, 30, 40};
    int val[] = {60, 100, 120, 240};

    cout << unboundedKnapsack(val, wt, n, w) << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < w + 1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
}

/*
//Important:
//ROD CUTTING problem is exactly the same as this
//Problem statement: 
//Given a rod of length n inches and an array of prices that contains prices of all 
  pieces of size smaller than n. Determine the maximum value obtainable by cutting 
  up the rod and selling the pieces. For example, if length of the rod is 8 and 
  the values of different pieces are given as following, then the maximum 
  obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

*/