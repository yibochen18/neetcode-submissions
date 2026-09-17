class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        return b_search(nums, target, l, r);
    }

    int b_search(vector<int> & nums, int target, int l, int r) {
        if (l > r) return -1;

        int mid = l + (r - l) / 2;

        if (nums[mid] == target) return mid;

        return nums[mid] > target ? b_search(nums, target, l, mid - 1) : b_search(nums, target, mid + 1, r);
    }
};
