#include <bits/stdc++.h>
using namespace std;

int t[102][102];

string lcsPrint(string x, string y, int m, int n)
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

    // here trace back the path from index m and n all the way to top
    string s = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
            {
                s.push_back(y[j - 1]);
                j--;
            }
            else
            {
                s.push_back(x[i - 1]);
                i--;
            }
        }
    } // s will store reverse of lcs

    while (i > 0)
    {
        s.push_back(x[i - 1]);
        i--;
    }

    while (j > 0)
    {
        s.push_back(y[j - 1]);
        j--;
    }

    reverse(s.begin(), s.end()); // s now stores the lcs

    return s;
}

int main()
{
    memset(t, -1, sizeof(t));
    string x = "aggtab";
    string y = "gxtxayb";
    int m = x.length(), n = y.length();

    string ans = lcsPrint(x, y, m, n);

    cout << "shortest common supersequence: " << ans << "\n";
}
