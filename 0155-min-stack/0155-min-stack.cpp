/* 
Idea: Hum stack me actual value nahi, kabhi-kabhi encoded value (2*val - minVal) store karte hain jab naya element current minimum se chhota hota hai. Isse purana minimum indirectly save ho jata hai.

Push: Agar val >= minVal hai to normally push karo. Agar val < minVal hai to encoded value push karo aur minVal = val update kar do.

Pop: Agar top encoded value hai (top < minVal), to iska matlab current minimum remove ho raha hai. Purana minimum formula (2*minVal - top) se wapas nikal lo, phir pop karo.

Top: Agar top encoded hai (top < minVal), to actual top value `minVal` hoti hai. Warna normal top hi answer hai.

Benefit: Sirf ek hi stack + ek variable (`minVal`) use hota hai, aur `push`, `pop`, `top`, `getMin` sab O(1) time aur O(1) extra space me ho jate hain.
*/

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else {
            if(val < minVal){
                s.push((long long)2*val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */