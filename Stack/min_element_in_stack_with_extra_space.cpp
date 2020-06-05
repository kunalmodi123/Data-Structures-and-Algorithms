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
stack<int> ss;

void push(int a)
{
    s.push(a);
    if (ss.size() == 0 || a <= ss.top())
        ss.push(a);
}

int pop()
{
    if (s.size() == 0)
        return -1;
    int ans = s.top();
    s.pop();

    if (ans == ss.top())
        ss.pop();
    return ans;
}

int getMin()
{
    if (ss.size() == 0)
        return -1;
    return ss.top();
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