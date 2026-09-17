class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int index = 0;

        for (const int & num : nums)
        {
            int complement = target - num;
            if (hashMap.count(complement))
            {
                return {hashMap[complement], index};
            }

            hashMap[num] = index;
            index++;
        }
        return {0, 0};
    }
};
