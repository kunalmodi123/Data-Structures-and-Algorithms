#include <bits/stdc++.h>

using namespace std;

bool isPairOfSum(int arr[], int n, int sum) // Sorted Array
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] + arr[right] == sum)
            return true;
        else if (arr[left] + arr[right] > sum)
            right--;
        else
            left++;
    }
    return false;
}

bool isPairForTriplet(int arr[], int left, int n, int sum) // Sorted Array and used in fuction to find triplet
{
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] + arr[right] == sum)
            return true;
        else if (arr[left] + arr[right] > sum)
            right--;
        else
            left++;
    }
    return false;
}

bool findTriplet(int arr[], int n, int sum) // Sorted Array
{
    for (int i = 0; i < n; i++)
    {
        if (isPairForTriplet(arr, i + 1, n, sum - arr[i]))
            return true;
    }
    return false;
}

bool isPairForPythagoras(int arr[], int right, int sum) // Sorted Array
{
    int left = 0;

    while (left < right)
    {
        if ((arr[left] * arr[left]) + (arr[right] * arr[right]) == sum)
            return true;
        else if ((arr[left] * arr[left]) + (arr[right] * arr[right]) > sum)
            right--;
        else
            left++;
    }
    return false;
}

bool ifPythagoras(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        if (isPairForPythagoras(arr, i - 1, arr[i] * arr[i]))
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ifPythagoras(arr, n) << endl;
}