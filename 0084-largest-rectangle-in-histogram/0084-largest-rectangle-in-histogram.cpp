// 1. for every index we will calculate the indices of the next smaller elements
// on right (rindex) and the previously smaller elemsnts on left (lindex)
// 2. Range of bars includes = [lindex+1, rindex-1]
// 3. No. of bars included = rindex-lindex-1
// 4. area = no. of bars included * heights[i]
// 5. we will keep track of the max area and return it
// 6. T.C. = O(n) [O(n) for computing the lindex and rindex for every element
// and then O(1) to compute the area]

class Solution {
public:
    vector<int> pse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>heights[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> nse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> left = pse(heights);
        vector<int> right = nse(heights);
        for(int i=0 ; i<n ; i++){
            int lindex = left[i];
            int rindex = right[i];
            int bars = rindex-lindex-1;
            int area = bars*heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};