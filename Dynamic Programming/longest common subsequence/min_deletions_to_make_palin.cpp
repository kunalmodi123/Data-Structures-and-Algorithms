#include <bits/stdc++.h>
using namespace std;

int t[102][102];

int lpsTab(string x, string y, int m, int n)
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

    return (m - t[m][n]); //Here we find the length of lps and then subtract it from size
                          // of original string x
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "afbchbta";
    string y = x;
    reverse(y.begin(), y.end());
    int m = x.length(), n = y.length();

    int ans = lpsTab(x, y, m, n);

    cout << "min deletions to make it palindrome: " << ans << "\n";
}

/*If we asked minimum number of insertions, then the answer remains same.

min # of DELETIONS to make palindrome = min # of INSERTIONS to make palindrome 

*/