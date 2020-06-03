#include <bits/stdc++.h>
using namespace std;

int t[102][102];

int lcsRec(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return (1 + lcsRec(x, y, m - 1, n - 1));
    else
        return max(lcsRec(x, y, m, n - 1), lcsRec(x, y, m - 1, n));
}

int lcsMemo(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (t[m][n] != -1)
        return t[m][n];

    if (x[m - 1] == y[n - 1])
        t[m][n] = 1 + lcsMemo(x, y, m - 1, n - 1);
    else
        t[m][n] = max(lcsMemo(x, y, m, n - 1), lcsMemo(x, y, m - 1, n));

    return t[m][n];
}

int lcsTab(string x, string y, int m, int n)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[m][n];
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "abedcf";
    string y = "baegcf";
    int m = x.length(), n = y.length();

    int count = lcsTab(x, y, m, n);

    cout << "longest common subsequence length: " << count << "\n";

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << t[i][j] << "\t";
        cout << endl;
    }
}