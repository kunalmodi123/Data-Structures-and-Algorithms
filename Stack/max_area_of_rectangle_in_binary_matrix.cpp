#include <bits/stdc++.h>
using namespace std;

vector<int> nslIndex(vector<int> a)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < a.size(); i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top().first < a[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= a[i])
        {
            while (s.size() > 0 && s.top().first >= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }

        s.push({a[i], i});
    }

    return v;
}

vector<int> nsrIndex(vector<int> a)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(a.size());
        else if (s.size() > 0 && s.top().first < a[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= a[i])
        {
            while (s.size() > 0 && s.top().first >= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(a.size());
            else
                v.push_back(s.top().second);
        }

        s.push({a[i], i});
    }

    reverse(v.begin(), v.end());

    return v;
}

int MAH(vector<int> a)
{
    vector<int> left = nslIndex(a);
    vector<int> right = nsrIndex(a);

    int maxEle = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = a[i] * (right[i] - left[i] - 1);
        maxEle = max(maxEle, a[i]);
    }

    return maxEle;
}

int main()
{
    int n = 4, m = 4;
    int arr[100][100] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    vector<int> v;
    for (int j = 0; j < m; j++)
        v.push_back(arr[0][j]);

    int mx = MAH(v);
        
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                v[j] = 0;
            else
                v[j] = v[j] + 1;
        }

        mx = max(mx, MAH(v));
    }

    cout << "Answer: " << mx;
}