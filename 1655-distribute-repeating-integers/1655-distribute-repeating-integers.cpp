class Solution
{
    public:
        bool solve(vector<int> &freq, vector<int> &quantity, int currCustomerIndex)
        {
           	// base case
            if(currCustomerIndex >= quantity.size()) {
                return true;
            }

           	// Recursion
            for (int i = 0; i < freq.size(); ++i)
            {

                if (freq[i] >= quantity[currCustomerIndex])
                {
                    freq[i] -= quantity[currCustomerIndex];

                    if (solve(freq, quantity, currCustomerIndex + 1))
                    {
                        return true;
                    }
                    else
                    {
                        // backtrack
                        freq[i] += quantity[currCustomerIndex];
                    }
                }
            }
            return false;
        }

    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        sort(quantity.rbegin(), quantity.rend()); // sort dec
        unordered_map<int, int> freqMap;

        for (auto num: nums)
        {
            freqMap[num]++;
        }

        vector<int> freq;

        for (auto it: freqMap)
        {
            freq.push_back(it.second);
        }

        return solve(freq, quantity, 0);
    }
};