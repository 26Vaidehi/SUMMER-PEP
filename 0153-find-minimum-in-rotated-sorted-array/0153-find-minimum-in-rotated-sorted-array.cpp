class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r = n-1;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r]) {
                // minimum is in right half
                l = m + 1;
            } else {
                // minimum is at m or in left half
                r = m;
            }
        }

        return nums[l];
    }
};