class Solution {
public:
    bool isPalindrome(string s) {

        if (s.length() == 1)
        {
            return true;
        }

        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
            {
                l++;
            }
            while (r > l && !isalnum(s[r]))
            {
                r--;
            }

            char left = tolower(s[l]);
            char right = tolower(s[r]);

            if (left == right)
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
