#include<bits/stdc++.h>
using namespace std;

// Maximum Path Sum in a 2D Matrix (You are allowed to start from top left and can move only right or bottom side)

const int N = 1e3;
int dp[N+1][N+1];
int arr[N][N];

int minPathSum(int r, int c)
{
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(i==1 && j == 1)
                dp[i][j] = arr[i-1][j-1];
            else if(i == 1 && j > 1)
                dp[i][j] = dp[i][j - 1] + arr[i-1][j-1];
            else if(j == 1 && i > 1)
                dp[i][j] = dp[i-1][j] + arr[i-1][j-1]; 
        }
    }

    for(int i=2; i<=r; i++)
    {
        for(int j=2; j<=c; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i-1][j-1];
    }

    return dp[r][c];
}

int main()
{
    int r, c;
    cin>>r>>c;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> arr[i][j];
    
    cout << "minPathSum: " << minPathSum(r, c) << "\n\n";
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++)
            cout <<  dp[i][j] << " ";
        cout << "\n";   
    }
}