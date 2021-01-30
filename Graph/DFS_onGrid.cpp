/*
You are given a 2D grid. A '#' represents an obstacle and a '.' represents free space.
You need to find the areas of the disconnected components. The cells (i+1, j), (i, j+1), (i-1, j), (i, j-1)
are the adjacent to the cell (i, j).

There are multiple test cases in this problem.

*/    
    
#include<bits/stdc++.h>
using namespace std;

const int N=3e3;

void dfs(vector<vector<char>>& grid,int row, int col, vector<vector<bool>>& visited, int& cnt){
    int r[] = {-1, 0, 0, 1};
    int c[] = {0, -1, 1, 0};
    cnt++; // for area of connected components

    int ROW = grid.size();
    int COL = grid[0].size();

    visited[row][col] = true;
        
    for(int k=0; k<4; k++){
        int a = row+r[k];
        int b = col+c[k];
        if((a >= 0) && (a < ROW) && (b >= 0) && (b < COL) && (grid[a][b] == '.' && !visited[a][b])){
                dfs(grid, a, b, visited, cnt);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){ 
        int row, col;
        cin >> row >> col;
        vector<vector<char>> grid(row, vector<char>(col));
        vector<vector<bool>> visited(row , vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin >> grid[i][j];
            }
        }

        int cnt = 0;
        vector<int> cnt1;
        int k = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '.' && !visited[i][j]){
                    dfs(grid, i, j, visited, k);
                    cnt++;
                    cnt1.push_back(k);
                    k = 0;
                }
            }
        }

        cout << cnt << "\n";
        for(auto x: cnt1)
            cout << x << " ";
        cout << "\n";
    }

}