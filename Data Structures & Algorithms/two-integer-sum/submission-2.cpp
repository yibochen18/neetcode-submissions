class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //could sort and then do two pointer approach but that is O(nlogn + n)
        // that would be O(1) space though so it might be good if we want minimum memory usage
        // hashmap for O(1) lookups

        unordered_map<int, int> hashmap;
        int diff;

        for (int i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];

            if (hashmap.find(diff) != hashmap.end())
            {
                return {hashmap[diff], i};
            }

            hashmap.insert({nums[i], i});
        }

        return {};
    }
};
