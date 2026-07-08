class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //1. sliding window -> keep increasing the window till we r not getting duplicates, and keep updating the map
        //2. if we encounter a duplicate, shrink the window from left, decrement the map frequency, left pointer ++, and right pointer value add to map and right++
        // right pointer se window badao, agar duplicate aa jaye, toh left pointer ko move krke duplicate hatao, fir answer update kro
        int left = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        int n = s.size();
        for(int right=0 ; right<n ;right++){
            while(mp[s[right]]>0){
                mp[s[left]]--;
                left++;
            }
            mp[s[right]]++;
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};