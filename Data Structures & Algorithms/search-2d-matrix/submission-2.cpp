class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size() - 1, n = matrix.size() - 1;

        for (auto vec : matrix)
        {
            if (vec[0] > target || vec[m] < target)
            {
                continue;
            }

            if (vec[0] <= target && vec[m] >= target)
            {
                return bsearch(0, m, vec, target);
            }
        }

        return false;
    }

    bool bsearch(int l , int r, vector<int> & nums, int target)
    {
        if (l > r) return false;

        int m = l + (r - l) / 2;

        if (nums[m] == target) return true;

        return nums[m] > target ? bsearch(l , m - 1, nums, target) :
            bsearch(m + 1, r, nums, target);
    }
};
