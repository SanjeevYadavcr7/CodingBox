class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, curr = 0, diff, s = 0;
        for(int i=0;i<n;i++){
            diff = gas[i] - cost[i];
            
            total += diff;
            curr += diff;
            if(curr < 0){
                s = i+1;
                curr = 0;
            }
            
        }
        if(total >= 0) return s;
        return -1;
    }
};
