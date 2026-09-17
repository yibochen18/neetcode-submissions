class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, min_index = 0;
        //binary sort to find minimum (index of that is the pivot point)
        bsearch_min(nums, min_index, l, r);

        cout << min_index << "\n";
        if (nums[min_index] == target) return min_index;
        return nums[r] < target ? bsearch(nums, target, l, min_index - 1) :
            bsearch(nums, target, min_index + 1, r);
    }

    void bsearch_min(vector<int> & nums, int & min_index, int l, int r) {
        if (l > r) return;
        int m = l + (r - l) / 2;

        if (nums[m] < nums[min_index]) min_index = m;

        nums[m] > nums[r] ? bsearch_min(nums, min_index, m + 1, r) :
            bsearch_min(nums, min_index, l, m - 1);
    }

    //bsearch the actual section that would have the target
    int bsearch(vector<int>& nums, int target, int l, int r) {
        cout << "bsearch with l and r " << l << " " << r << endl;
        if (l > r) return -1;

        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;

        return nums[mid] > target ? bsearch(nums, target, l, mid - 1) :
            bsearch(nums, target, mid + 1, r);
    }
};
