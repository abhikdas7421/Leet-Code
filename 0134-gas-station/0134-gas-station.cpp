class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // petrol remaning
        int balance = 0;
        // petrol kam pada
        int deficit = 0;
        // circuti starting point
        int start = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            balance += gas[i]-cost[i];
            
            if(balance < 0) {
                // deficit += balance;
                deficit += abs(balance);
                balance = 0;
                start = i+1;
            }
        }
        
        // if(deficit+balance >= 0) {
        //     return start;
        // }
        if(balance >= deficit) {
            return start;
        }
        return -1;
    }
};