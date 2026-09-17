class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            if (!set.insert(s[r]).second) {
                while (set.find(s[r]) != set.end()) {
                    set.erase(s[l]);
                    l++;
                }
            }

            set.insert(s[r]);
            ans = set.size() > ans ? set.size(): ans;
        }

        return ans;
    }
};
