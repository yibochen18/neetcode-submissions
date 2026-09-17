class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = b_search(nums, 0, nums.size() - 1, target);
        return ans;
    }

    int b_search(vector<int>& nums, int l, int r, int &target) {
        if (l > r) return -1;

        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        
        return nums[mid] > target ? b_search(nums, l, mid - 1, target) : b_search(nums, mid + 1, r, target);
    }
};
