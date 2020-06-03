/*
Problem 1:
A string is given with unbalanced parentheses. Print all the combination
of balanced strings formed by the removal of minimum number of paratheses
from the given string.
*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
    bool isBalanced(string s)
    {
        int cnt = 0;
        for (auto x : s)
        {
            if (x == '(')
                cnt++;
            else if (x == ')')
                cnt--;
            if (cnt < 0)
                return 0;
        }

        return (cnt == 0);
    }

public:
    map<string, bool> vis;
    vector<string> removeInvalidParantheses(string s)
    {
        queue<string> q;
        vector<string> ans;
        q.push(s);
        int found = 0;
        while (!q.empty())
        {
            string u = q.front();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            if (isBalanced(u))
                found = 1, ans.push_back(u);
            if (found)
                continue;
            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == '(' || u[i] == ')')
                {
                    string v = u.substr(0, i) + u.substr(i + 1, u.size() - i);
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    solution c;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Balanced strings with minimum removals are: \n";

    vector<string> v = c.removeInvalidParantheses(s);

    for (auto x : v)
    {
        cout << x << "\n";
    }

    return 0;
}
