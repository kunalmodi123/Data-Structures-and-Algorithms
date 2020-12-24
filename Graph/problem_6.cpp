/*
See if there is a word (given) in a 2d matrix. You cannot move diagonally in the matrix.
*/
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 5


bool recurse(char grid[R][C], string word, int n, int i, int r, int c){
    int l = word.length();
    if(i == l) return true;

    if((r < 0) || (c < 0) || (r >= n) || (c >= n+1)) return false;

    if(grid[r][c] == word[i]){

        char temp = grid[r][c];
        grid[r][c] = '#';

        // bool res = false;
        // int rows[] = {-1, 1, 0, 0};
        // int cols[] = {0, 0, -1, 1};
        // for(int k=0; k<4; k++){
        //     res = res|recurse(grid, word, n, i + 1, r + rows[k], c + cols[k]);
        // }

        bool res = recurse(grid, word, n, i+1,r - 1, c) |
                    recurse(grid, word, n, i+1, r + 1, c) |
                    recurse(grid, word, n, i+1,r, c - 1) |
                    recurse(grid, word, n, i+1, r, c + 1);

        grid[r][c] = temp;
        return res;
    }
    else
    {
        return false;
    }
    
}

bool findAns(char grid[R][C], string word, int n){
    for(int i=0; i<n; i++){
        for(int j=0; i<n+1; j++){
            if(grid[i][j] == word[0]){
                if(recurse(grid, word, n, 0, i, j))
                    return true;
            }
        }
    }

    return false;
}

int main(){
    int n = 4;
    char grid[R][C] = {"ABCD", "EFGH", "IJKL", "MNOP"};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    string word = "FGK";

    bool x = findAns(grid, "FGK", n);
    if(x) cout << "YES";
    else cout << "NO";
}