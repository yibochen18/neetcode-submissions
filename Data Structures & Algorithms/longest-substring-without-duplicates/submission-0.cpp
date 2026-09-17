class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dupset;
        int ans = 0;
        int l = 0;

        for (int i = 0; i< s.size(); i++)
        {
            //if it already exists in the set, then we should remove everything
            //up to that char
            while (dupset.find(s[i]) != dupset.end())
            {
                dupset.erase(s[l]);
                l++;
            }
            dupset.insert(s[i]);
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};
