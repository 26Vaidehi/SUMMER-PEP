class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
       for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
        else{
            if(st.empty()) return false;
            char topChar = st.top();
            if(s[i]==')' && topChar=='(' || s[i]==']' && topChar=='[' || s[i]=='}' && topChar=='{') st.pop();
            else{
                return false;
            }
        }
       }
       return (st.empty());
    }
};