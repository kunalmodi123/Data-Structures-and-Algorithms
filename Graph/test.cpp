// C++ program to check if the word 
// exists in the grid or not 
#include <bits/stdc++.h> 
using namespace std; 
#define r 4 
#define c 5 

// Function to check if a word exists in a grid 
// starting from the first match in the grid 
// level: index till which pattern is matched 
// x, y: current position in 2D array 
bool findmatch(char mat[r][c], string pat, int x, int y, int nrow, int ncol, int level) 
{ 
    int l = pat.length(); 

    // Pattern matched 
    if (level == l) 
        return true; 

    // Out of Boundary 
    if (x < 0 || y < 0 || x >= nrow || y >= ncol) 
        return false; 

    // If grid matches with a letter while 
    // recursion 
    if (mat[x][y] == pat[level]) { 

        // Marking this cell as visited 
        char temp = mat[x][y]; 
        mat[x][y] = '#'; 

        // finding subpattern in 4 directions 
        bool res = findmatch(mat, pat, x - 1, y, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x + 1, y, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x, y - 1, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x, y + 1, nrow, ncol, level + 1); 

        // marking this cell 
        // as unvisited again 
        mat[x][y] = temp; 
        return res; 
    } 
    else // Not matching then false 
        return false; 
} 

// Function to check if the word exists in the grid or not 
bool checkMatch(char mat[r][c], string pat, int nrow, int ncol) 
{ 

    

    // Traverse in the grid 
    for (int i = 0; i < nrow; i++) { 
        for (int j = 0; j < ncol; j++) { 

            // If first letter matches, then recur and check 
            if (mat[i][j] == pat[0]) 
                if (findmatch(mat, pat, i, j, nrow, ncol, 0)) 
                    return true; 
        } 
    } 
    return false; 
} 
// Driver Code 
int main() 
{ 
    char grid[r][c] = { "abcd", 
                        "efgh", 
                        "ijkl", 
                        "mnop" }; 

    // Function to check if word exists or not 
    if (checkMatch(grid, "fgk", r, c)) 
        cout << "Yes"; 
    else
        cout << "No"; 

return 0; 
} 