class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        //filling first element of dp with grid's first cell
        dp[0][0]=grid[0][0];

        //filling first row
        for(int j=1;j<m;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }

        //filling first column
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        //filling remaining cells 
        // 1. first take min of upper cell and left cell
        // 2. then add it with the value of current cell in grid
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int mini = min(dp[i][j-1],dp[i-1][j]);
                dp[i][j]=mini+grid[i][j];
            }
        }

        //return last cell
        return dp[n-1][m-1];

    }
};