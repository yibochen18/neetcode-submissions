class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!set.insert(s[i]).second) {
                while (set.find(s[i]) != set.end()) {
                    set.erase(s[l]);
                    l++;
                }
            }

            set.insert(s[i]);
            ans = set.size() > ans ? set.size(): ans;
        }

        return ans;
    }
};
