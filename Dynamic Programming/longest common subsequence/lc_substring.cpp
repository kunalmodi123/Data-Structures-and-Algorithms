#include <bits/stdc++.h>
using namespace std;

int t[102][102];

int lcSubstr(string x, string y, int m, int n)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    int maxVal = INT_MIN;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = 0; // changing this line from lcs original code(equals it to 0)

            maxVal = max(maxVal, t[i][j]); // also, the max value is calculated in the matrix as the common substring can be anywhere
        }
    }

    return maxVal; // return the maximum length
}
int main()
{
    memset(t, -1, sizeof(t));
    string x = "a";
    string y = "ab";
    int m = x.length(), n = y.length();

    int count = lcSubstr(x, y, m, n);

    cout << "longest common substring length: " << count << "\n";

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << t[i][j] << "\t";
        cout << endl;
    }

}