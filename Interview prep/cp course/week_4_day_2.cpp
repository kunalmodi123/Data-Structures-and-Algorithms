/*ktgm*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debList(list) for(auto x: list) cout << x << " "; cout << endl
#define rep(i, x, n) for (int i = x; i < n; i++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))

const int mod = 1000000007;
const int N = 200005;
/****************************************************************/
//Always check for long long


    int power(int x, int n, int mod){
        int ans = 1;
        while(n > 0){
            if(n%2 == 0){
                x = (x*x)%mod;
                n = n >> 1;
            }
            else{
                ans = (ans*x)%mod;
                n = n-1;
            }
        }

        return ans;
    }

/*
Rolling hash function (the formula used here can be any formula)
*/

    pair<int, int> rollingHash(string s){
        int n = s.size();

        int pr1 = 1;
        int pr2 = 1;

        int mod1 = (int)(1e9 + 7);
        int mod2 = (int)(1e9 + 9);

        int hash1 = 0;
        int hash2 = 0;

        for(int i=0; i<n; i++){
            hash1 = (hash1 + ((s[i] - 'a' + 1)*pr1)%mod1)%mod1;
            hash2 = (hash2 + ((s[i] - 'a' + 1)*pr2)%mod2)%mod2;

            pr1 = (pr1 * 29) % mod1;
            pr2 = (pr2 * 31) % mod2;
        }

        return {hash1, hash2};
    }

/*
Given a string, print number of distinct substrings in it
*/
    int distinctSubstring(string s){
        int n = s.size();
        set<int> st;

        for(int i=0; i<n; i++){
            int hash = 0;
            int mod = (int)(1e9 + 7);
            int pr = 1;
            for(int j=i; j<n; j++){
                hash = (hash + ((s[j] - 'a' + 1)*pr)%mod)%mod;
                pr = (pr * 29)%mod;

                st.insert(hash);
            }
        }

        return st.size();
    }
    // TC - O(N^2(log(N^2)))

/*
Given a string s and q queries. Each query will have 4integers, l1, r1, l2, r2. Check for each query if,
substring(l1, r1) is equal to substring(l2, r2) or not
*/

    void isEqual(){
        string s;
        cin >> s;
        int n = s.size();

        vector<int> pref(n);
        int hash = 0;
        int mod = (int)(1e9 + 7);
        int pr = 1;

        for(int i=0; i<n; i++){
            hash = (hash + ((s[i] - 'a' + 1)*pr)*mod)*mod;
            pr = (pr * 29)%mod;

            pref[i] = hash;
        }

        int q;
        cin >> q;
        while(q--){
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            int hash1 = pref[r1];
            if(l1 > 0) hash1 = (hash1 - pref[l1-1] + mod)%mod;
            hash1 = (hash1 * power( power(29, l1, mod), mod-2, mod))%mod;

            int hash2 = pref[r2];
            if(l2 > 0) hash2 = (hash2 - pref[l2-1] + mod)%mod;
            hash2 = (hash2 * power( power(29, l2, mod), mod-2, mod))%mod;

            if(hash1 == hash2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    // TC - O(N + Q*log(mod)) 
    
/*
RABIN KARP ALGORITHM
*/
    void rabinKarp(string str, string pattern){
        int n = str.size();
        int mod = (int)(1e9 + 7);
        int pr = 1;
        int patternHash = 0;
        int k = pattern.size();
        for(int i=0; i<k; i++){
            patternHash = (patternHash + ((pattern[i] - 'a' + 1)*pr)%mod)%mod;
            pr = (pr*29)%mod;
        }

        int cnt = 0;
        vector<int> indices;
        int pr1 = 1, pr2 = 1;
        int hash = 0;

        // calculating answer for first window
        for(int i=0; i<k; i++){
            hash = (hash + ((str[i] - 'a' + 1)*pr1)%mod)%mod;
            pr1 = (pr1*29)%mod;
        }

        if(hash = patternHash){
            indices.push_back(0);
            cnt++;
        }

        int l = 0, r = k-1;
        while(r != n-1){

            // adding next window's answer
            r++;
            hash = (hash + ((str[r] - 'a' + 1)*pr1)%mod)%mod;
            pr1 = (pr1*29)%mod;
            
            // subtracting previous window answer
            hash = (hash - ((str[l] - 'a' + 1)*pr2)%mod + mod)%mod;
            pr2 = (pr2*29)%mod;
            l++;

            // to adjust the power of primes in patternHash
            patternHash = (patternHash * 29)%mod;

            if(hash = patternHash){
                cnt++;
                indices.push_back(l);
            }
        }

        cout << cnt << endl;
        for(auto it: indices)
            cout << it << " ";
        cout << endl;
    }

/*
Good Subtrings - Codeforces
// https://codeforces.com/problemset/problem/271/D
*/
    void solve(){
        string s, freq;
        cin >> s >> freq;
        int k; 
        cin >> k;
        int n = s.size();
        set<pair<int, int>> st;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            int hash1 = 0, hash2 = 0;
            int mod1 = (int)(1e9 + 7);
            int mod2 = (int)(1e9 + 9);
            int pr1 = 1, pr2 = 1;
            cnt = 0;
            for(int j=i; j<n; j++){
                if(freq[s[j] - 'a'] == '0')
                    cnt++;
                if(cnt > k) break;
                
                hash1 = (hash1 + ((s[j] - 'a' + 1)*pr1)%mod1)%mod1;
                pr1 = (pr1 * 29)%mod1;
                
                hash2 = (hash2 + ((s[j] - 'a' + 1)*pr2)%mod2)%mod2;
                pr2 = (pr2 * 31)%mod2;
                
                

                st.insert({hash1, hash2});
            }
        }
        
        cout << st.size() << "\n";
    }

/*
Longest Prefix Substring - lps array
*/
    vector<int> generateLPS(string s){
        int n = s.size();
        int len = 0, i = 1;
        vector<int> lps(n, 0);
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len) len = lps[len-1];
                else i++;
            }
        }

        return lps;
    }

/*
KMP Algorithm
*/
    int kmpAlgo(string s, string pat){
        vector<int> lps = generateLPS(pat + '#' + s);
        int cnt = 0;
        for(int i = 0; i<(int)(lps.size()); i++){
            if(lps[i] == pat.size())
                cnt++;
        }

        return cnt;
    }



// signed main(){
//     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif

//     int t = 1;
//  //   cin >> t;
//     while(t--)
// //solve();
// }