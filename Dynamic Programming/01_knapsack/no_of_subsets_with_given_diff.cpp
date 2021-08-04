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


int answerCount(int arr[], int n, int diff)
{
    int sumArr = 0;
    for (int i = 0; i < n; i++)
        sumArr += arr[i];

    // sum1 + sum2 = totalSum ------------ 1
    // sum1 - sum2 = diff --------------2
    // 1 + 2,
    // 2*sum1 = diff + totalSum
    // => sum1 = (diff + totalSum)/2; //
    int sum = (diff + sumArr) / 2;

    return countSubsetSum(arr, n, sum);
}

int main()
{
    int n = 4, diff = 1;
    int arr[] = {1, 1, 2, 3};

    int h = answerCount(arr, n, diff);

    cout << "count: " << h << endl
         << endl;
}

// Important:
//TARGET SUM is exactly the same problem with one step further do check
// basically we the count the no. of ways we can assigns signs to the array elements
// such that the sum of array elements equals to the given sum