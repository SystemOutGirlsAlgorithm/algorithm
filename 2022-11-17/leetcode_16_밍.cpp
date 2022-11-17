class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int first = 0, last = nums.size() - 1, sum, res = nums[first] + nums[1] + nums[last];
        sort(nums.begin(), nums.end());
        
        for (; first < nums.size() - 2; first++) {
            for (int i = first + 1, last = nums.size() - 1; i < last;) {
                sum = nums[first] + nums[i] + nums[last];
                if (sum == target) return sum;
                else if (sum > target) {
                    if(abs(sum - target) < abs(res - target)) res = sum;
                    last--;
                }
                else {
                    if(abs(sum - target) < abs(res - target)) res = sum;
                    i++;
                }
            }
        }
        
        return res;
    }
};