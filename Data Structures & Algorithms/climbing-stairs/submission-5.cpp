class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        //either climb one or climb 2
        vector<int> steps(n + 1);
        steps[1] = 1;
        steps[2] = 2;

        // # of ways to climb stairs is the sum of the previous 2

        for (int i = 3 ; i <= n; i++) {
            steps[i] = steps[i-1] + steps[i-2]; 
        }

        return steps[n];
    }
};
