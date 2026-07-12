// 1. Binary search on answer (ship capacity).
// 2. Search space = [max(weights), sum(weights)].
// 3. For each capacity, simulate shipping greedily and count days.
// 4. If daysUsed <= days, capacity is valid -> try smaller (r = mid).
// 5. Else capacity is too small -> increase it (l = mid + 1).
class Solution {
public:
    bool isValidCap(vector<int>& weights, int days, int cap){
        int daysUsed = 1;
        int currWt = 0;
        for(int& w : weights){
            if(currWt+w <= cap){
                //load it
                currWt += w;
            }
            else{
                //start a new day
                daysUsed++;
                currWt = w;
            }
        }
        return daysUsed <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r){
            int m = l+(r-l)/2;
            if(isValidCap(weights,days,m)){
                r = m;  //trying smaller capacity
            }
            else{
                l = m+1;    //trying higher capacity
            }
        }
        return l;
    }
};