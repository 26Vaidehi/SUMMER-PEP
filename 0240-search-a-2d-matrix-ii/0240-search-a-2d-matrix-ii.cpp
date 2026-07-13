// The idea is we will start from the upper rightmost element (curr)
// if curr > target, we know that we will not get the target in the curr column, so we we shift in left column
// now repeat step 2 until we got curr<=target
// if the curr < target, we know that there is a chance we will find the target in that column, so we will search in that column
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //starting from 1st row, last column
        int row = 0;
        int col = m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++; //search down in that column
            else col--; //search in left column of current column
        }
        return false;
    }
};