/*
Approach:

1. t ke saare characters ki frequency map bana lo.

2. Sliding window use karenge.
   - r pointer se window expand karenge.
   - Jo character window me aayega uski frequency map me decrease karenge.
   - Agar woh character required tha (freq > 0), to required count kam kar denge.

3. Jab required == 0 ho jaye,
   matlab current window me t ke saare characters aa gaye hain.

4. Ab l pointer se window shrink karenge.
   - Har valid window ka minimum length update karenge.
   - Left character ko remove karte time uski frequency increase karenge.
   - Agar frequency positive ho gayi, matlab ab woh character missing ho gaya.
     Window invalid ho jayegi, shrinking stop.

5. Phir dobara r ko move karke window expand karenge.

6. Puri string traverse hone ke baad minimum window return kar denge.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;
        int required = t.size();
        int l = 0;
        int start = 0;
        int minlen = INT_MAX;
        for(int r=0 ; r<s.size() ; r++){
            if(mp[s[r]]>0) required--;
            mp[s[r]]--;
            while(required==0){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    start=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) required++;
                l++;
            }
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};