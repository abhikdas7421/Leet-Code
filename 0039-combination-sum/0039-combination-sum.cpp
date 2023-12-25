class Solution
{
    public:
        void combinationSumHelper(vector<int> &candidates, int target, int index, vector<vector< int >> &combn, vector< int > &v)
        {
            if (target == 0)
            {
                combn.push_back(v);

                return;
            }

            for (int i = index; i < candidates.size(); i++)
            {
               	//                 if(target-candidates[i] >= 0) {

               	//                     v.push_back(candidates[i]);

               	//                     combinationSumHelper(candidates, target-candidates[i], i, combn, v);

               	//                    	// backtracking
               	//                     v.pop_back();

               	//                 }

                if(candidates[i] > target) break;

                v.push_back(candidates[i]);
                combinationSumHelper(candidates, target - candidates[i], i, combn, v);
               	// backtracking
                v.pop_back();
            }
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector < int>> combn;
        vector<int> v;
        combinationSumHelper(candidates, target, 0, combn, v);

        return combn;
    }
};