#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
const int mod = 1e9+7;

bool isSafe(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
    int ROW = grid.size();
    int COL = grid[0].size();

    return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && !visited[row][col]);
}

vector<vector<int>> bfs(int ROW, int COL, int row, int col){
    int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<int>> grid(ROW, vector<int>(COL, 0));
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    visited[row][col] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push({1, {row, col}});
    while(!q.empty()){
        pair<int, pair<int, int>> node = q.front();
        q.pop();
        for(int k=0; k<8; k++){
            int a = node.second.first+r[k];
            int b = node.second.second+c[k];
            if(isSafe(grid, a, b, visited)){
                visited[a][b] = true;
                grid[a][b] = node.first;
                q.push({node.first+1, {a, b}});
            }
        }
    }

    return grid;
}



void solve(){
    int r, c, R, C;
    cin >> r >> c >> R >> C;
    vector<vector<int>> ans = bfs(r, c, R, C);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}