#include <bits/stdc++.h>
using namespace std;
// MINIMUM NO. OF INSERTIONS AND DELETIONS TO CHANGE X TO Y
int t[102][102];

int minInsDel(string x, string y, int m, int n)
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

    return (m + n - 2 * t[m][n]); // (subtracting length of lcs from a to find deletions, then doing the same
                                  // with b to find min deletions. Then we add both to get the final equation
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "heap";
    string y = "pea";
    int m = x.length(), n = y.length();

    int ans = minInsDel(x, y, m, n);

    cout << "answer: " << ans << "\n";
}