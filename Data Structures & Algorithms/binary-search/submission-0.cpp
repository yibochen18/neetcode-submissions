class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, index = 0;

        while (l <= r)
        {
            index = l + (r - l) / 2; //this is to prevent overflow
            if (nums[index] < target)
            {
                // in right subarray
                l = index + 1;
            }
            else if (nums[index] > target)
            {
                //in left subarray
                r = index -1;
            }
            else
            {
                return index;
            }
        }

        return -1;
    }
};
