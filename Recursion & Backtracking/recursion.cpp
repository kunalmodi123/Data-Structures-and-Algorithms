#include<bits/stdc++.h>
using namespace std;

// important string printing technique in recursion
// this function is to print every possible binary string of length n with no consecutive 1's 
void printPattern(int n, string osf){
    if(n == 0){
        cout << osf << "\n";
        return;
    }

    printPattern(n - 1, osf + '0');
    if((osf.size() !=0) && (osf[osf.size() - 1]) == '0')
        printPattern(n-1, osf + '1');
}

// function to determine if a array is sorted or not
bool isSorted(vector<int> arr, int n){
    if(n == 0)
        return true;

    if(isSorted(arr, n-1) && arr[n-1] < arr[n])
        return true;

    return false;
}

// Print all the subsets of elements ina vector
void printSubset(vector<int> v, int i, int n, string osf){
    if(i == n){
        cout << "["<<osf<<"]\n";
        return;
    }

    printSubset(v, i+1, n, osf + to_string(v[i]) + ",");

    printSubset(v, i+1, n, osf);
}

void dicePath(int i, int n, string osf){
    if(i >= n) return;
    if(i == n-1){
        cout << osf << endl;
        return;
    }

    for(int j=1; j<=6; j++)
        dicePath(i+j, n, osf + to_string(j) + "->");
}

void lexico(int i, int n){
    if(i > n) return;
    cout << i << "\n";
    for(int j = ( i==0 )?1:0 ; j<=9; j++)
        lexico(10*i+j, n);
}

void permutation(string str, string osf){
    if(str.size() == 0){
        cout << osf << "\n";
        return;
    }

    unordered_set<char> st; // to handle cases of duplicates

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(st.count(ch) == 0){ // for handling duplicates
            string ros = str.substr(0, i) + str.substr(i+1);
            st.insert(ch);
            permutation(ros, osf + ch);
        }
    }
}

int main(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    // if(isSorted(a, a.size()-1))
    //     cout << "Yes";
    // else cout << "No";

    //lexico(0, 100);
    // printSubset(a, 0, n, "");

  //  dicePath(0, 4, "");

    permutation("ABCB", "");
}