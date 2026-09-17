class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window approach
        unordered_map<char, int> freqMap;
        int l = 0, ans = 0, maxFreq = 0;
        
        for (int r = 0; r < s.length(); r++)
        {
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);

            // auto it = max_element(freqMap.begin(), freqMap.begin() + r,
            // [](const pair<char, int> &p1, const pair<char, int> &p2)
            // {
            //     return p1.second < p2.second;
            // });


            // int maxFreq = it->second;

            // if the number of replacements exceed allowed amount
            while ((r - l + 1) - maxFreq > k)
            {
                //shrink the window
                freqMap[s[l]]--;
                l++;
            }

            ans = max(ans, (r - l + 1));
        }

        return ans;
    }
};
