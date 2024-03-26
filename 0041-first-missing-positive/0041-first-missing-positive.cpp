class Solution {
public:
    // Approach 1:- T.C:- O(nlogn) | S.C:- O(1)
    /*int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int firstMisEle = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0 || nums[i] < firstMisEle) {
                continue;
            }
            else if(nums[i] == firstMisEle) {
                firstMisEle++;
            }
            else if(nums[i] > firstMisEle) {
                break;
            }
        }

        return firstMisEle;
    }*/

    // Approach 2:- T.C:- O(n) | S.C:- O(n)
    /*int firstMissingPositive(vector<int>& nums) {
        set<int> freq;

        for(int &num : nums) {
            if(num <= 0) {
                continue;
            }
            else {
                freq.insert(num);
            }
        }

        int firstMisEle = 1;
        for(auto &it : freq) {
            if(it == firstMisEle) {
                firstMisEle++;
            }
            else {
                break;
            }
        }

        return firstMisEle;
    }*/

    // Approach 3:- Best approach | T.C:- O(n) | S.C:- O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {

            int x = nums[i];

            while((x >= 1 && x <= n) && (nums[x-1] != nums[i]) && (nums[i] != i+1)) {
                swap(nums[x-1], nums[i]);
                x = nums[i];
            }
        }

        int i = 0;
        for(; i < n; i++) {
            if(nums[i] != i+1) {
                break;
            }
        }

        return i+1;

    }
};