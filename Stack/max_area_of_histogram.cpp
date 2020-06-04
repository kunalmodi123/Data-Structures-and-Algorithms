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

int main()
{
    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    vector<int> left = nslIndex(a);
    vector<int> right = nsrIndex(a);

    int maxEle = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = a[i] * (right[i] - left[i] - 1);
        maxEle = max(maxEle, a[i]);
    }

    cout << "Maximum area of histogram: " << maxEle;
}