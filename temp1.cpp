#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char x = tolower(s[3]);
    cout << s << " " << tolower(s[3]) << " " << x <<"\n";
    toupper(s[3]);
    cout << s << " " << toupper(s[3]) <<"\n";
}