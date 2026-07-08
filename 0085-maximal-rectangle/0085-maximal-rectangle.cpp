class Solution {
public:
    vector<int> pse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> nse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = pse(heights);
        vector<int> right = nse(heights);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};