class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
        grid[i][j]=0;
        dfs(grid,i,j+1,n,m); // top
        dfs(grid,i,j-1,n,m); //bottom
        dfs(grid,i+1,j,n,m); //right
        dfs(grid,i-1,j,n,m); //left
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){//if boundary land cell
                    if(grid[i][j]==1){//if not visited and is land cell
                        dfs(grid,i,j,n,m); //find connected components
                        grid[i][j]=0;   //turn them 0
                    }
                }
            }
        }
        //count remaining land cells (not on boundary)
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};