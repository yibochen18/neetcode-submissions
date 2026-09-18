class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            // Update left + right to point at valid alphaNum chars
            while (left < right && !isAlphaNum(s[left])) {
                left++;
            }
            while (left < right && !isAlphaNum(s[right])) {
                right--;
            }

            //need to make them lowercase before comparing
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }

    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z'
        || c >= 'a' && c <= 'z'
        || c >= '0' && c <= '9');
    }
};
