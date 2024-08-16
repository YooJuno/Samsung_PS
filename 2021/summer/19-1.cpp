class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size(), tot = (1 << n);
        for (int i = 0; i < tot; ++i) {
            int xorsum = 0;
            for (int j = 0; j < n; ++j) if ((i >> j) & 1) xorsum ^= nums[j]; 
            ans += xorsum;
        }
        return ans;
    }
};