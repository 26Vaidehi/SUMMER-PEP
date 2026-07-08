class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int ans = 0;
        int maxFreq= 0 ;
        unordered_map<char,int> mp;
        for(int right=0 ; right<n ; right++){
            mp[s[right]-'A']++; //window expanding
            maxFreq = max(maxFreq, mp[s[right]-'A']);   //frequncy incrementing and taking max frequency

            //window size = right-left+1
            //number of replacements = window size - maxFrequency
            // jab tk replacements>k h tb tak window shrink karni h aur left poi8nter ko aage badhana h
            while((right-left+1)-maxFreq > k){
                mp[s[left]-'A']--;
                left++;
            }

            // ans hamesha r-l+1 hoga (window ka size)
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};