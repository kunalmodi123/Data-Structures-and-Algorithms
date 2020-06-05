#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define INPUT freopen("input.txt", "r", stdin)
#define MOD 1000000007

stack<int> s;
int minEle = INT_MAX;

void push(int a)
{
    if (s.size() == 0)
    {
        s.push(a);
        minEle = a;
    }
    else
    {
        if (a >= s.top())
            s.push(a);
        else
        {
            s.push(2 * a - minEle);
            minEle = a;
        }
    }
}

int top()
{
    if (s.size() == 0)
        return -1;
    else
    {
        if (s.top() >= minEle)
            return s.top();
        else
            return minEle;
    }
}

void pop()
{
    if (s.size() == 0)
        cout << "Stack Already Empty"
             << "\n";
    else
    {
        if (s.top() >= minEle)
            s.pop();
        else
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
}

int getMin()
{
    if (s.size() == 0)
        return -1;
    return minEle;
}

int main()
{
    push(18);
    push(19);
    push(29);
    push(15);
    cout << getMin() << endl;
    pop();
    cout << getMin() << endl;
    pop();
    cout << getMin() << endl;
}