class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;
    
        unordered_map<char, int> st1, st2;
        for (int i = 0 ; i < s.length(); i++) {
            st1[s[i]]++;
        }

        for (int j = 0; j < t.length(); j++) {
            st2[t[j]]++;
        }

        if (st1 == st2) return true;
        return false;
    }
};
