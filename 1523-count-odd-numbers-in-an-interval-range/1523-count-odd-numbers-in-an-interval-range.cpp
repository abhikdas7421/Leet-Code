class Solution {
public:
    int countOdds(int low, int high) {
        
        int odd = (high-low)/2;
        
        if(low&1 == 1 || high&1 == 1) {
            odd++;
        }
        
        return odd;
        
    }
};
