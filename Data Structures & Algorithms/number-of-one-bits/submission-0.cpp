class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i =0; i < 32; i++) {
            //& is bitwise &, && is logical and
            if ((n >> i & 1) != 0) ans++;
        }

        return ans;
    }
};
