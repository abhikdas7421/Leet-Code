class Solution
{
    public:
        string expandAroundIndices(string &s, int i, int j)
        {
            int l = i;
            int h = j;

            while (l >= 0 && h < s.size() && s[l] == s[h])
            {

                l--;
                h++;
            }

            string str = s.substr(l + 1, h - l - 1);

            return str;
        }

        string longestPalindrome(string & s)
        {

            string ans = "";

            for (int i = 0; i < s.size(); i++)
            {
                // O(n^2)
                // odd

                string oddStr = expandAroundIndices(s, i, i);
                // cout << oddStr << endl;

                // even

                string evenStr = expandAroundIndices(s, i, i + 1);
                // cout << evenStr << endl;

                // compare size of oddStr, evenStr and ans
                if (oddStr.size() > evenStr.size() && oddStr.size() > ans.size())
                {

                    ans = oddStr;
                }
                else if (evenStr.size() > ans.size())
                {

                    ans = evenStr;
                }
            }

            return ans;
        }
};