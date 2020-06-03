#include <bits/stdc++.h>
using namespace std;

bool t[102][1002];

void subsetSum(int arr[], int n, int sum)
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
}
int range = 0;
int minimumDiff(int arr[], int n)
{

    for (int i = 0; i < n; i++) // We calculate the total sum of array elements
        range += arr[i];

    subsetSum(arr, n, range); // to change the t array

    vector<int> lastRow; // where we store the range index in the last row of t array

    for (int j = 0; j <= range / 2; j++) // inserting indexes to the vector till half of range
    {
        if (t[n][j] == true)
            lastRow.push_back(j);
    }
    // We only inserted half of the elements so as to get positive number while calculating minimum value below

    // for (auto x : lastRow)
    //     cout << x << " ";
    // cout << endl;

    int minVal = INT_MAX;
    for (auto x : lastRow)
        minVal = min(minVal, range - (2 * x)); // Very important: to calculate the minimum difference

    return minVal;
}

int main()
{
    int n = 5;
    int arr[] = {4, 7, 5, 3, 8};

    int h = minimumDiff(arr, n);

    cout << "min Diff: " << h << endl;

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < range + 1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
}