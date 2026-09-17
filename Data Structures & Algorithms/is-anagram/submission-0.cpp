class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1, m2;

        for (const char c: s)
        {
            m1[c]++;
        }

        for (const char c: t)
        {
            m2[c]++;
        }

        if (m1 == m2)
        {
            return true;
        }

        return false;
    }
};
