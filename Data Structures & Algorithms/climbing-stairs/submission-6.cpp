class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        return dfs(n, cache);
    }

    int dfs(int n, vector<int>& cache) {
        // Base cases:
        if (n == 0) return 1; // 1 way to stay at the ground (do nothing)
        if (n == 1) return 1; // Only 1 way to reach step 1 (single 1-step)
        if (cache[n] != -1) return cache[n];

        // Ways to reach n = ways to reach (n-1) + ways to reach (n-2)
        cache[n] = dfs(n - 1, cache) + dfs(n - 2, cache);
        return cache[n];
    }
};