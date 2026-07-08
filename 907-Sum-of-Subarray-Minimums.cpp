class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevSmall = pse(nums);
        vector<int> nextSmall = nse(nums);

        long long sumMin = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;

            sumMin = (sumMin + (1LL * nums[i] * left % MOD) * right) % MOD;
        }

        return sumMin;
    }
};