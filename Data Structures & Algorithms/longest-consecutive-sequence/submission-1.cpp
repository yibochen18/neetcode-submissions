class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //nlogn + n, just sort and then count but that is O(nlogn)

        //keep track of what we've seen before and some method to determine if there is some valid sequence
        if (nums.empty()) return 0;
        int maxLength = 1; //if it isn't empty it must have at least 1 :D

        //hashset, traverse n elemenets O(n)
        unordered_set<int> seen;
        for (const auto & num: nums) {
            seen.insert(num);
        }

        for (const auto & num: nums) {
            //check if the num is a valid seq start
            if (!seen.contains(num - 1)) {
                int currentNum = num;
                int currLength = 1;

                while (seen.contains(currentNum + 1)) {
                    currentNum++;
                    currLength++;
                    maxLength = max(currLength, maxLength);
                }
            }
        }

        return maxLength;
    }
};
