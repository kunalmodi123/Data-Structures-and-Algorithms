#include <bits/stdc++.h>
using namespace std;

int t[102][102];

int scsTab(string x, string y, int m, int n)
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
    } // till here, the code is exactly the same as lcs tabular

    return (m + n - t[m][n]); // worst case(concatenating both the strings) minus the common subsequence
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "abedcf";
    string y = "baegcf";
    int m = x.length(), n = y.length();

    int ans = scsTab(x, y, m, n);

    cout << "shortest common supersequence length: " << ans << "\n";
}