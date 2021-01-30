/*ktgm*/

/*
find the maximum distance from any 0 to its nearest 1(manchester distance i.e. |xf - xi| + |yf - yi|)
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debList(list) for(auto x: list) cout << x << " "; cout << endl
#define fo(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, sizeof(x))

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1e9+7;
const int N = 2e5;
/****************************************************************/

int bfs(vector<vector<int>>& grid,int i, int j){
    int cnt = 0;
    int R = grid.size();
    int C = grid[0].size();
    int rows[] = {-1, 1, 0, 0};
    int cols[] = {0, 0, -1, 1};

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[i][j] = true;
    queue<pii> q;
    q.push({i, j});
    while(!q.empty()){
        pii node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;

        for(int k=0; k<4; k++){
            int r = x + rows[k];
            int c = y + cols[k];
            if((r >= 0) && (r < R) && (c >= 0) && (c < C) && !visited[r][c]){
                visited[r][c] = true;
                if(grid[r][c] == 1){
                    cnt = abs(i - r) + abs(j - c);
                    return cnt;
                }
                q.push({r, c});
            }
        }
    }

    return -1;
}

int solve(vector<vector<int>>& grid){

    int ans = 0;
    int R = grid.size();
    int C = grid[0].size();
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(grid[i][j] == 0){
                int cnt = bfs(grid, i, j);
                ans = max(cnt, ans);
            }
        }
    }

    return ans;
}

int main(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cin >> grid[i][j];
    }

    int ans = solve(grid);
    cout << ans;
}
