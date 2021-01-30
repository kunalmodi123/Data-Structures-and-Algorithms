
/*
    Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t = 1;
   // cin >> t;
    while (t--) {
        int n=4;
        int m[MAX][MAX] = {{1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}};

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<vector<bool>> vis(MAX, vector<bool>(MAX, false));
vector<string> ans;

bool isSafe(int m[MAX][MAX], int n, int r, int c){
    return (r >= 0 and r < n and c >= 0 and c < n and !vis[r][c]);
}

void dfs(int m[MAX][MAX], int n, int r, int c, string osf){
    if(r == 0 and c == 0 and m[r][c] == 0)
        return;
    if(r == n-1 and c == n-1){
        ans.push_back(osf);
        return;
    }
    
    vis[r][c] = true;
    int rows[] = {0, 0, -1, 1};
    int cols[] = {-1, 1, 0, 0};
    
    char dir[] = {'L', 'R', 'U', 'D'};
    for(int k=0; k<4; k++){
        int x = r + rows[k];
        int y = c + cols[k];
        if(isSafe(m, n, x, y) && m[x][y] == 1){
            dfs(m, n, x, y, osf+dir[k]);
            vis[x][y] = false;
        }
    }
}


vector<string> findPath(int m[MAX][MAX], int n) {
    ans.clear(); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            vis[i][j] = false;
    }
    dfs(m, n, 0, 0, "");
    sort(ans.begin(), ans.end());
    return ans;
}