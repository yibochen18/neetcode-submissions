class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window
        unordered_map<char, int> freqMap;
        int l = 0;
        int maxLen = 0;
        int maxFreq = 0;

        for (int r = 0; r < s.length(); r++) {
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);

            //if the # of replacements > k then we move the left pointer
            while ((r - l + 1) - maxFreq > k) {
                freqMap[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
