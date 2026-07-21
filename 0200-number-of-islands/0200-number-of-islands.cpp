class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){
        //base case (if out of bounds, already visited, '0' h)
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1') return;
        vis[i][j]=true;
        dfs(i-1,j,vis,grid,n,m);    //top
        dfs(i+1,j,vis,grid,n,m);    //bottom
        dfs(i,j-1,vis,grid,n,m);    //left
        dfs(i,j+1,vis,grid,n,m);    //right
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;  //no. of islands
        int n = grid.size();    //rows
        int m = grid[0].size();     //columns
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){  //not visited and is '1'
                    dfs(i,j,vis,grid,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};