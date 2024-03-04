class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size();
        int low = 0;
        int high = n-1;
        
        int score = 0;
        
        while(low <= high) {
            if(power >= tokens[low]) {
                power -= tokens[low];
                score++;
                low++;
            }
            else if(low < high && score > 0) {
                power += tokens[high];
                score--;
                high--;
            }
            else {
                return score;
            }
            
        }
        
        return score;
    }
};