class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, mul = nums[0], l = 1, r = 1;
        if (nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            l *= nums[i];
            r *= nums[nums.size()-1 - i];
            ans = max(ans, max(l, r));
            if (l == 0) l = 1;
            if (r == 0) r = 1;
        }
        return ans;
    }
};