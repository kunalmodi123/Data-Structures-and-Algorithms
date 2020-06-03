#include <bits/stdc++.h>
using namespace std;

int t[102][102];

bool stringMatchingSubsequence(string x, string y, int m, int n)
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
                j--;
            else
                i--;
        }
    } // s will store reverse of lcs

    reverse(s.begin(), s.end()); // s now stores the lcs which may or may not beb equal to x

    if (x == s) // If true, then x is a subsequence of y
        return true;
    else
        return false;
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "agf";
    string y = "baegch";
    int m = x.length(), n = y.length();

    bool res = stringMatchingSubsequence(x, y, m, n);

    cout << "Is '" << x << "' a subsequence of '" << y << "' ?: ";
    if (res)
        cout << "YES";
    else
        cout << "NO";
}

// Or better solution is to directly compare the length of lcs and x.
// Both can only be equal if they are same
// so if(m == s.length()) return true; else return false;