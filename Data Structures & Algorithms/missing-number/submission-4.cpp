class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // [0, 1, 2, 3, 4, 6]
        // [0, 1, 2, 3, 4, 5, 6]
        // xor, a xor a = 0, 0 xor b = b
        int ans = 0;
        for (int num :nums) {
            ans ^= num;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            ans ^= i;
        }
        //everything cancels out except missing element
        return ans;
    }
};
