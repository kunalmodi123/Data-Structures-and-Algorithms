#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int l, int h, int x) //Array should be sorted
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2; // or better l + (h - l)/2;

    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        return binarySearch(arr, mid + 1, h, x);
    else
        return binarySearch(arr, l, mid - 1, x);
}

int leftMostIndex(vector<int> arr, int l, int h, int x) //Array should be sorted
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2; // or better l + (h - l)/2;

    if (arr[mid] == x && (mid == 0 || arr[mid - 1] != x))
        return mid;
    if (arr[mid] < x)
        return leftMostIndex(arr, mid + 1, h, x);
    else
        return leftMostIndex(arr, l, mid - 1, x);
}

int rightMostIndex(vector<int> arr, int l, int h, int x, int n) //Array should be sorted
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2; // or better l + (h - l)/2;

    if (arr[mid] == x && (mid == (n - 1) || arr[mid + 1] != x))
        return mid;
    if (arr[mid] <= x) //equalto sign because we will go right even if we find the element 
        return rightMostIndex(arr, mid + 1, h, x, n);
    else
        return rightMostIndex(arr, l, mid - 1, x, n);
}

int countOccurences(vector<int> arr, int x) //Array should be Sorted
{   
    int n = arr.size();
    int l = leftMostIndex(arr, 0, n - 1, x);
    int r = rightMostIndex(arr, 0, n - 1, x, n);

    int count = r - l + 1;

    return count;
}

int findInInfArr(vector<int> arr, int x) //Array should be Sorted
{
    if (arr[0] == x)
        return x;
    int i = 1;

    while (arr[i] < x)
        i = i * 2;
    if (arr[i] == x)
        return i;
    else
        return binarySearch(arr, i / 2, i, x);
}

int findPivot(vector<int> arr, int l, int h)
{
    if (h < l)
        return -1;
    if (h == l)
        return l;
    int mid = (l + h) / 2;
    if (mid < h && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > l && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[l] >= arr[mid]) // equal but how?
        return findPivot(arr, l, mid - 1);
    return findPivot(arr, mid + 1, h);
}

int pivotBS(vector<int> arr, int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
    if (arr[pivot] == key)
        return pivot;
    if (arr[0] > key)
        return binarySearch(arr, pivot + 1, n - 1, key);
    return binarySearch(arr, 0, pivot - 1, key);
}

int squareRoot(int x)
{
    if (x == 0 || x == 1)
        return x;
    int start = 1;
    int end = x;

    int ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid; // since we need floor so we update ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    // vector<int> arr = {1, 1, 2, 3, 4, 4, 4, 5, 6, 6, 7, 8, 4, 4, 8, 9, 11, 11, 12};
    //int n = sizeof(arr) / sizeof(arr[0]);
    // int n = arr.size();
    // sort(arr.begin(), arr.end());
    // int x;
    // cout << "Enter the value of x: ";
    // cin >> x;

    // int l = leftMostIndex(arr, 0, n - 1, x);
    // int r = rightMostIndex(arr, 0, n - 1, x, n);
    // int count = countOccurences(arr, x);

    // cout << l << "\n"
    //      << r;
    // cout << endl
    //      << count;
    cout << "\nThe square root is: ";
    cout << squareRoot(10);
}