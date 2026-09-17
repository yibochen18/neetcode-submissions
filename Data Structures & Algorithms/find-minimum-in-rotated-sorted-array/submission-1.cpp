class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        int min = nums[mid];

        if (nums[mid] > nums[r]) {
            //search right
            b_search(nums, min, mid + 1, r);
        }
        else {
            b_search(nums, min, l, mid - 1);
        }

        return min;
    }

    void b_search(vector<int> &nums, int &min, int l, int r) {
        if (l > r) return;
        int mid = l + (r - l) / 2;
        
        if (nums[mid] < min) min = nums[mid];

        nums[mid] > nums[r] ? b_search(nums, min, mid + 1, r)
            : b_search(nums, min, l, mid - 1);
    }
};
