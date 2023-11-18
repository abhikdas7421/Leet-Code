class Solution {
public:
    bool isPosSoln(vector<int>& weights, int days, int soln) {
        int weightCount = 0;
        int day = 1;

        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > soln) return false;

            if(weightCount + weights[i] > soln) {
                day++;
                weightCount = weights[i];

                if(day > days) return false;
            }
            else {
                weightCount += weights[i];
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(isPosSoln(weights, days, mid)) {
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        
        return ans;
    }
};