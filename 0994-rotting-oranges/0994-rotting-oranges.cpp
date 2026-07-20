/*
    1. Create a visited grid to store the state of the cell (fresh, rotten, or empty).
    2. Initialize a queue to store the rotten oranges and count the number of fresh oranges.
    3. Check if there are no fresh oranges, return 0, or if there are no rotten oranges, return -1.
    4. Loop while the queue is not empty.
        a. Store the size of the queue.
        b. Loop through the size of the queue.
                i. Get the front cell of the queue.
                ii. Check all four directions of the cell to see if there are any fresh oranges.
                iii. If there is a fresh orange, change its state to rotten and decrement the count of fresh oranges, and push the cell into the queue.
        c. Increment the minutes.
    5. If there are no fresh oranges, return the minutes.
    6. If there are still fresh oranges, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis = grid;
        queue<pair<int,int>> q; //in q we will fill rotting oranges
        int cnt = 0;    //count of fresh oranges

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==2){
                    q.push({i,j});
                }
                if(vis[i][j]==1) cnt++;
            }
        }

        // there are no fresh oranges 
        if (cnt==0) return 0;
        // there are no rotting oranges
        if(q.empty()) return -1;

        int minutes = -1;

        // we will cover all 4 directions (up, down,left,right)
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x,y] = q.front();
                q.pop();
                for(auto& [dx,dy] : dirs){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && i<n && j>=0 && j<m && vis[i][j]==1){ //if i&j are in bound and it is fresh
                        vis[i][j]=2;    // rot that fresh orange
                        cnt--; //decrement the count of fresh orange
                        q.push({i,j});  //push the cell in q
                    }
                }
            }
            minutes++;
        }

        if(cnt == 0) return minutes;
        return -1;
    }
};