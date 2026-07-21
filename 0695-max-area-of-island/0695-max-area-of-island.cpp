class Solution {
public:

    // DFS function island ki area return karega
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m,
            vector<vector<bool>>& vis){

        // Base Case:
        // 1. Grid ke bahar chale gaye
        // 2. Water cell (0) mil gaya
        // 3. Cell pehle hi visit ho chuka hai
        if(i < 0 || j < 0 || i >= n || j >= m ||
           grid[i][j] == 0 || vis[i][j])
            return 0;

        // Current cell ko visited mark kar do
        vis[i][j] = true;

        // Current cell ki area = 1
        // + upar ki area
        // + neeche ki area
        // + left ki area
        // + right ki area
        return 1
             + dfs(grid, i+1, j, n, m, vis)   // Down
             + dfs(grid, i-1, j, n, m, vis)   // Up
             + dfs(grid, i, j+1, n, m, vis)   // Right
             + dfs(grid, i, j-1, n, m, vis);  // Left
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Visited array taaki same cell dobara process na ho
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int maxArea = 0;

        // Har cell se DFS start karenge agar:
        // 1. Land hai
        // 2. Visit nahi hua
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1 && !vis[i][j]){

                    // Is poore island ki area nikalo
                    int area = dfs(grid, i, j, n, m, vis);

                    // Maximum area update karo
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};