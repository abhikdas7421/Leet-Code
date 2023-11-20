class Solution
{
    public:
        bool isAnagram(string s, string t)
        {

            if (s.size() != t.size()) return false;

            vector<int> freqTable(26, 0);

            for (int i = 0; i < s.size(); i++)
            {
                freqTable[s[i] - 'a']++;
            }

            for (int i = 0; i < t.size(); i++)
            {
                freqTable[t[i] - 'a']--;
            }

            for (int i = 0; i < 26; i++)
            {
                if (freqTable[i] != 0)
                {
                    return false;
                }
            }

            return true;
        }
};