// Recursion, Backtracking, Priority queue

/*
    maximum Stack Space = 10^7

    if it overflows then we will get SEGMENTATION FAULT
*/

#include<bits/stdc++.h>
using namespace std;

// recursive function to check if a string is palindrome or not
bool palindrome(int l, int r, string s){
    if(l > r)
        return true;
    if(s[l] != s[r])
        return false;
    return palindrome(l+1, r-1, s);
}

//------------------------------------------------------------------------------------------------------------//

//printing all subsequences of an array
// PICK/NON-PICK TECHNIQUE
void printSubsequences(int ind, vector<int> &ds, vector<int> arr){
    if(ind == arr.size()){
        for(auto x: ds){ 
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    //pick
    ds.push_back(arr[ind]);
    printSubsequences(ind+1, ds, arr);
    ds.pop_back(); //backtracking step

    //non-pick
    printSubsequences(ind+1, ds, arr);
} //TC - O(n*(2^n)) (printing take order of N time)


//count the number of subsequences whose sum is divisible by 'k'
// technique to solve count related problems without using any extra space and array
int count(int ind, int sum, vector<int> &arr, int k){
    if(ind == arr.size()){
        if(sum % k == 0) return 1;
        return 0;
    }

    int l = count(ind + 1, sum + arr[ind], arr, k); //pick
    int r = count(ind + 1, sum, arr, k); //non-pick

    return l+r;
} //It also counts empty set i.e. (sum=0)%k == 0 condition will be true and we will get 1 more answer
// so final answer = ans - 1

//-------------------------------------------------------------------------------------------------------------------------//

//ADD ANY ELEMENT AT ANY STEP TECHNIQUE
// can be used to solve problems which is based on duplicates etc
// for this do 
// 1. subset sum II, 2. combination sum II

//---------------------------------------------------------------------------------------------------------------------------//

// print permutations of a string
// also see striver: print all permutation approach 2 from youtube
void printPermutations(int ind, string ans, string s, map<int, int> &mpp, int n){
    if(ind == n){
        cout << ans << "\n";
        return;
    }

    for(int i=0; i<n; i++){
        if(!mpp[i]){
            mpp[i] = 1;
            ans += s[i];

            printPermutations(ind+1, ans, s, mpp, n);

            mpp[i] = 0;
            ans.pop_back();
        }
    }
}

//print all paths to travel from (0, 0) to (n-1, m-1) in a matrix
void printPaths(int i, int j, string ans, int n, int m){
    if(i == n-1 and j == m-1){
        cout << ans << "\n";
        return;
    }

    //down
    if(i+1 < n){
        ans += 'D';
        printPaths(i+1, j, ans, n, m);
        ans.pop_back();
    }

    //right
    if(j+1 < m){
        ans += 'R';
        printPaths(i, j+1, ans, n, m);
        ans.pop_back();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------//

//Rat in a maze problem - classical backtracking problem
int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, 1, -1};
string dir = "UDRL";
void ratInAMaze(int i, int j, string ans, vector<vector<int>> &vis, vector<vector<int>> &maze, int n, int m){
    if(i == n-1 and j == m-1){
        cout << ans << "\n";
        return;
    }
    // vis[i][j] = 1;  // this also gives right answer and is more intuitive to understand
    for(int k=0; k<4; k++){
        int newi = i + dx[k];
        int newj = j + dy[k];
        if(newi >= 0 and newj >= 0 and newj < m and newi < n and vis[newi][newj] == 0 and maze[newi][newj] == 1){
            vis[i][j] = 1;
            ratInAMaze(newi, newj, ans + dir[k], vis, maze, n, m);
            vis[i][j] = 0;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------//

//printing all the solutions of Nqueen problem
void NQueens(int col, int N, vector<vector<int>> &chessboard, vector<int> row, vector<int> lower, vector<int> upper){
    if(col == N){
        for(auto i: chessboard){
            for(auto j: i){
                if(j == 1)
                    cout << "Q ";
                else cout << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(row[i] == 0 and lower[i+col] == 0 and upper[N - 1 + (col-i)] == 0){
            chessboard[i][col] = 1;

            //hashing
            row[i] = 1;
            lower[i+col] = 1;
            upper[N-1 + (col-i)]= 1;

            NQueens(col+1, N, chessboard, row, lower, upper);

            //unhashed
            chessboard[i][col] = 0;
            row[i] = 0;
            lower[i+col] = 0;
            upper[N-1 + (col-i)]= 0;
            
        }
    }
}

// printing one solution
bool NQueens2(int col, int N, vector<vector<int>> &chessboard, vector<int> row, vector<int> lower, vector<int> upper){
    if(col == N){
        for(auto i: chessboard){
            for(auto j: i){
                if(j == 1)
                    cout << "Q ";
                else cout << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
        return true;
    }

    for(int i=0; i<N; i++){
        if(row[i] == 0 and lower[i+col] == 0 and upper[N - 1 + (col-i)] == 0){
            chessboard[i][col] = 1;

            //hashing
            row[i] = 1;
            lower[i+col] = 1;
            upper[N-1 + (col-i)]= 1;

            if(NQueens2(col+1, N, chessboard, row, lower, upper) == true)
                return true;
            //unhashed
            chessboard[i][col] = 0;
            row[i] = 0;
            lower[i+col] = 0;
            upper[N-1 + (col-i)]= 0;
            
        }
    }
    return false;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

//priority queue - 
// find kth smallest element
int kthSmallest(vector<int>& arr, int k){
    int n = arr.size();
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
    vector<int> arr = {2, 7, 9, 3, 5, 8, 6};
    int k = 5;
    vector<int> ds;
    map<int, int> mpp;
    string s = "modi";
    int n = 4, m = 4;
    int N = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<int> row(N, 0);
    vector<int> lower(2*N - 1, 0);
    vector<int> upper(2*N - 1, 0);

    // printSubsequences(0, ds, arr);
    // cout << count(0, 0, arr, k) << "\n";

    // printPermutations(0, "", s, mpp, s.size());
    // printPaths(0, 0, "", n, m);
    // cout << "\n";

    // cout << "rat in a maze: \n";
    // ratInAMaze(0, 0, "", vis, maze, n, m);

    // cout << "\nNqueen for N = " << N << ":\n";
    // NQueens(0, 4, board, row, lower, upper);

    // cout << "\nNqueens(1 solution only) for N = " << N << ":\n";
    // bool ans = NQueens2(0, 4, board, row, lower, upper);

    cout << "\nkth smallest element: " << kthSmallest(arr, 4);


}