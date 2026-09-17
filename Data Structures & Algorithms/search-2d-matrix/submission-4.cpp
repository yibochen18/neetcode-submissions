class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search the matrix itself for the correct row log(m)
        // then binary search the row log(n), total log(n) + log(m) = log(n * m);
        int m = matrix.size() - 1, n = matrix[0].size() - 1;

        int valid_index = c_bsearch(matrix, 0, m, target);

        return bsearch(0, n, matrix[valid_index], target);

        // while (start <= end)
        // {
        //     int mid = start + (end - start) / 2;

        //     if (matrix[mid][0] <= target && matrix[mid][n] >= target)
        //     {
        //         return bsearch(0, n, matrix[mid], target);
        //     }
        //     else if (matrix[mid][0] >= target)
        //     {
        //         end = mid - 1;
        //     }
        //     else
        //     {
        //         start = mid + 1;
        //     }
        // }

        return false;
    }

    //function to return index of potential vector
    int c_bsearch(vector<vector<int>> & matrix, int start, int end, int target)
    {   
        int n = matrix[0].size() - 1;
        if (start > end) return 0;

        int mid = start + (end - start) / 2;

        if (matrix[mid][0] <= target && matrix[mid][n] >= target)
        {
            return mid;
        }

        return matrix[mid][0] >= target ? c_bsearch(matrix, start, mid - 1, target)
            : c_bsearch(matrix, mid + 1, end, target);

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
