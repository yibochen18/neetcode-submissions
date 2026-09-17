#include <limits.h>

class Solution {
public:
    int findMin(vector<int> &nums) {
        //if midpoint is > end, search right
        //if midpoint is < end, search left
        int min = INT_MAX;
        int l = 0, r = nums.size() - 1;

        return b_search(nums, l, r, min);
    }

    int b_search(vector<int> &nums, int l, int r, int & min)
    {
        if (l > r) return min;

        int mid = l + (r - l) / 2;

        if (nums[mid] < min)
        {
            min = nums[mid];
        }

        return nums[mid] > nums[r] ? b_search(nums, mid + 1, r, min) 
            : b_search(nums, 0, mid - 1, min);
    }
};
