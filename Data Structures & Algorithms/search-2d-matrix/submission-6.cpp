class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //b search for the right row, and then bsearch that row for the number
        int m = matrix[0].size() - 1, n = matrix.size() - 1;
        int row = bsearch_col(matrix, target, 0, n);

        if (row == -1) return false;
        else return bsearch_row(matrix[row], target, 0, m);
    }

    int bsearch_col(vector<vector<int>>& matrix, int target, int t, int b){
        if (t > b) return -1;

        int m = t + (b - t) / 2;
        if (matrix[m][0] <= target && matrix[m][matrix[0].size() - 1] >= target) return m;

        return matrix[m][0] > target ? bsearch_col(matrix, target, t, m - 1) :
            bsearch_col(matrix, target, m + 1, b);
    }

    bool bsearch_row(vector<int> &row, int target, int l, int r) {
        if (l > r) return false;

        int m = l + (r - 1) / 2;

        if (row[m] == target) return true;
        
        return row[m] > target ? bsearch_row(row, target, l, m - 1) :
            bsearch_row(row, target, m + 1, r);
    }
};
