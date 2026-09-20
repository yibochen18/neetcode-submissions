class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> str1, str2;
        for (int i = 0; i < s.length(); i++) {
            str1[s[i]]++;
        }
        for (int j = 0; j < t.length(); j++) {
            str2[t[j]]++;
        }

        if (str1 == str2) return true;
        return false;
    }
};
