class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){

        // Base Case:
        // 1. Grid ke bahar chale gaye
        // 2. Cell 'O' nahi hai (ya toh 'X' hai ya pehle hi '#' mark ho chuka hai)
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;

        // Boundary se connected 'O' ko temporarily '#'
        // mark kar rahe hain taaki baad me ise flip na karein.
        board[i][j] = '#';

        // 4 directions me DFS
        dfs(board, i + 1, j, n, m); // Down
        dfs(board, i - 1, j, n, m); // Up
        dfs(board, i, j + 1, n, m); // Right
        dfs(board, i, j - 1, n, m); // Left
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // STEP 1:
        // Sirf boundary ke 'O' se DFS chalao.
        // Jo bhi 'O' boundary se connected honge,
        // un sabko '#' bana do.

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                // Agar boundary cell hai aur 'O' hai
                if((i == 0 || i == n-1 || j == 0 || j == m-1)
                    && board[i][j] == 'O'){

                    dfs(board, i, j, n, m);
                }
            }
        }

        // STEP 2:
        // Ab poori board traverse karo.
        //
        // 'O'  -> Ye boundary se connected nahi tha,
        //         matlab surrounded region hai.
        //         Isko 'X' bana do.
        //
        // '#' -> Ye boundary se connected tha.
        //        Isko wapas 'O' bana do.

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};