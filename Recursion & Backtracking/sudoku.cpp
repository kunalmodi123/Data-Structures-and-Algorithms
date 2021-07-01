#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> ans;
int cnt=0;

bool isSafe(vector<vector<char>>& grid, int r, int c, char ch){
    vector<int> box = {0, 0, 0, 3, 3, 3, 6, 6, 6};

    for(int i=0; i<9; i++){
        if(grid[i][c] == ch) return false;;
    }

    for(int j=0; j<9; j++){
        if(grid[r][j] == ch) return false;
    }

    for(int i=box[r]; i<box[r]+3; i++){
        for(int j=box[c]; j<box[c]+3; j++){
            if(grid[i][j] == ch) return false;
        }
    }

    return true;
}

void sudokuSolver(vector<vector<char>>& grid, int r, int c){
    if(r == 9){
        cnt++;
        ans = grid;
        return;
    }

    if(grid[r][c] == '_'){
        for(char i='1'; i<='9'; i++){
            if(isSafe(grid, r, c, i)){
                grid[r][c] = i;
                if(c == 8)
                    sudokuSolver(grid, r + 1, 0);
                else 
                    sudokuSolver(grid, r, c+1);
                grid[r][c] = '_';
            }
        }
    }
    else{
        if(c == 8)
            sudokuSolver(grid, r + 1, 0);
        else 
            sudokuSolver(grid, r, c+1);
    }
}

int main(){
    
    vector<vector<char> > grid = {
        {'5', '3', '_', '_', '7', '_', '_', '_', '_'},
        {'6', '_', '_', '1', '9', '5', '_', '_', '_'},
        {'_', '9', '8', '_', '_', '_', '_', '6', '_'},
        {'8', '_', '_', '_', '6', '_', '_', '_', '3'},
        {'4', '_', '_', '8', '_', '3', '_', '_', '1'},
        {'7', '_', '_', '_', '2', '_', '_', '_', '6'},
        {'_', '6', '_', '_', '_', '_', '2', '8', '_'},
        {'_', '_', '_', '4', '1', '9', '_', '_', '5'},
        {'_', '_', '_', '_', '8', '_', '_', '7', '9'}
    };

    sudokuSolver(grid, 0, 0);

    cout << "No. of Solutions exists: " << cnt;

    cout << "\nOne of the solution(on the right side): \n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << grid[i][j] << " ";
            if((j+1)%3 == 0) cout << " ";
        }
        cout << "\t";
        for(int j=0; j<9; j++){
            cout << ans[i][j] << " ";
            if((j+1)%3 == 0) cout << " ";
        }

        if((i+1)%3 == 0) cout << endl;
        cout << endl;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}