class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        //base case
        if(obstacleGrid[0][0]==1) return 0;

        // 1 -> OBSTACLE   0 -> EMPTY CELL

        // making an answer grid to calculate no. of paths
        vector<vector<int>> dp(n, vector<int>(m, 0));

        //marking first cell i.e. starting cell with 1
        dp[0][0]=1;

        //filling the first row and first column of dp grid with 1 , excluding the obstacle cells(0)
        for(int j=1;j<m;j++){
            if(obstacleGrid[0][j]==0){
                dp[0][j]=dp[0][j-1];
            }
        }        
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0]=dp[i-1][0];
            }
        }

        //filling the remaining cells
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                //if there is an obstacle in original grid, mark that cell as 0 in dp grid
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    dp[i][j] = dp[i][j-1]+dp[i-1][j];
                }
            }
        }

        return dp[n-1][m-1];
    }
};