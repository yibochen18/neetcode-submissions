class Solution {
public:
    int climbStairs(int n) {
        //possible ways is the sum of the previous two numbers..?
        vector<int> oogabooga(n + 1, 0);
        oogabooga[1] = 1;
        oogabooga[2] = 2;
        int ans = 0;

        if (n <= 2) return n;

        for (int i = 3; i <= n; i++)
        {
            ans = (oogabooga[i - 1] + oogabooga[i - 2]);
            oogabooga[i] = ans;
        }

        return ans;
    }
};
