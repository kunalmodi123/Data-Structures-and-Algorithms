#include <bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> a)
{
    vector<int> v;
    stack<pair<int, int>> s; // to store the element and also track the index of it

    for (int i = 0; i < a.size(); i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top().first > a[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first <= a[i])
        {
            while (s.size() > 0 && s.top().first <= a[i])
                s.pop();

            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }

        s.push(make_pair(a[i], i));
    }

    int k = 0;
    for (auto &x : v)
    {
        x = k - x;
        k++;
    }

    return v;
}

// This is a variation of "Nearest greater to left" problem
// Here we store the indices of all the nearest greatest to left elements and
// then subtract the content of obtained vector with its corresponding indices to get the answer vector

int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = StockSpan(a);

    for (auto x : v)
        cout << x << " ";
}