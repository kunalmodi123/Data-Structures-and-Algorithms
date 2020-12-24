// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    int r[] = {-1, 0, 0, 1};
    int c[] = {0, -1, 1, 0};

  //  vector<vector<bool>> visited(R, vector<bool>(C, false));
    
    queue<pair<int, pair<int, int>>> q;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] == 2){
                q.push({0, {i, j}});
           //     visited[i][j] = true;
            }
        }
    }

    

    int ans = 0;
    while(!q.empty()){
        pair<int, pair<int, int>> node = q.front();
        q.pop();
        int t = node.first;
        ans = max(t, ans);
        
        for(int k=0; k<4; k++){
            int x = node.second.first + r[k];
            int y = node.second.second + c[k];
            if((x>=0) && (x<R) && (y>=0) && (y<C) && (matrix[x][y] == 1)){
                matrix[x][y] = 2;
                q.push({t+1, {x, y}});
               // visited[x][y] = true;
            }
        }
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] == 1)
                return -1;
        }
    }
    
    return ans;
}

// { Driver Code Starts.

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends