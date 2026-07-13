//The idea is simple, we will convert the 2D matrix into a 1D array and will simply apply binary search on that array.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();  //total rows
        int m = matrix[0].size();   //total columns
        int l = 0;
        int r = (n*m)-1;
        while(l<=r){
            int mid = l+(r-l)/2;

            //Flatten 2D matrix
            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) l=mid+1;
            else r=mid-1;
        }   
        return false;
    }
};