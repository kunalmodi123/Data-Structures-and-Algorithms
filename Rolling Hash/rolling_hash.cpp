#include <bits/stdc++.h>

using namespace std;

void rollingHash(string s, string p)
{
    cout << endl
         << endl;
    int flag = 0;
    int hash = 0, curr_hash = 0;

    if (p.size() > s.size())
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < p.size(); i++)
    {
        hash += (int)(p[i] - 'a') + 1;
        curr_hash += (int)(s[i] - 'a') + 1;
    }

    if (curr_hash == hash)
    {
        cout << s.substr(0, p.size()) << "\n";
        flag = 1;
    }

    for (int i = 0; i < (s.size() - p.size()); i++)
    {
        curr_hash = curr_hash + (int)(s[i + p.size()] - 'a') + 1 - ((int)(s[i] - 'a') + 1);
        if (curr_hash == hash)
        {
            cout << s.substr(i + 1, p.size()) << "\n";
            flag = 1;
        }
    }

    if (!flag)
        cout << -1 << "\n";
    return;
}

int main()
{
    string s, p;
    cout << "Enter the main string: ";
    cin >> s;
    cout << "\nEnter the subtring: ";
    cin >> p;

    rollingHash(s, p);
    return 0;
}
