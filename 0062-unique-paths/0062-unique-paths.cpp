class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m));
        //filling first row and first column with 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0) dp[i][j]=1;
                else if(j==0) dp[i][j]=1;
            }
        }
        //calculating the value for rest cells with the sum of its left and upper cell
        //filling it with the max of its diagonal cell value and the sum we calculated
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int sum = dp[i][j-1]+dp[i-1][j];
                dp[i][j]=max(dp[i-1][j-1],sum);
            }
        }
        //returning the last cell value which is total number of ways to reach that cell
        return dp[n-1][m-1];
    }
};