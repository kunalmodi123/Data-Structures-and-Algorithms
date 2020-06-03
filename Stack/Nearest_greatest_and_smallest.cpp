#include <bits/stdc++.h>
using namespace std;

vector<int> NearestGreaterToRight(vector<int> a)
{
    vector<int> v;
    stack<int> s;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() > a[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() <= a[i])
        {
            while (s.size() > 0 && s.top() <= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }

        s.push(a[i]);
    }

    reverse(v.begin(), v.end());

    return v;
}

vector<int> NearestGreaterToLeft(vector<int> a)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < a.size(); i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() > a[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() <= a[i])
        {
            while (s.size() > 0 && s.top() <= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }

        s.push(a[i]);
    }

    return v;
}

vector<int> NearestSmallestToLeft(vector<int> a)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < a.size(); i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() < a[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() >= a[i])
        {
            while (s.size() > 0 && s.top() >= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }

        s.push(a[i]);
    }

    return v;
}

vector<int> NearestSmallestToRight(vector<int> a)
{
    vector<int> v;
    stack<int> s;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() < a[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() >= a[i])
        {
            while (s.size() > 0 && s.top() >= a[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }

        s.push(a[i]);
    }

    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    vector<int> a = {4, 5, 2, 10, 8};
    vector<int> v = NearestSmallestToRight(a);

    for (auto x : v)
        cout << x << " ";
}