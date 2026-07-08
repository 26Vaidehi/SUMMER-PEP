class Solution {
public:
    string removeKdigits(string num, int k) {
        //1. if we r targetting to get the smallest possible integer, we will focus on the leftmost significant digits and they should be smaller 
        //2. push digit in stack, if it is smaller than top element then pop and k--
        //3. edge cases are important here
        //   k==0 return num
        //   k still left and st is not empty, then keep popping top and k--
        //4. remove leading zeroes
        int n = num.size();
        if(k==0) return num;
        stack<char> st;
        for(int i=0 ; i <n ; i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //if k is still left
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            char c =  st.top();
            st.pop();
            ans += c;
        }
        reverse(ans.begin(),ans.end());
        //removing leading zeroes
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};