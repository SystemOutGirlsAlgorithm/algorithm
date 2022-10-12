class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        int left = 0, right = 1;
        
        while(left < nums.size() - 1) {
            if (nums[left] + nums[right] == target) {
                res[0] = left;
                res[1] = right;
                break;
            }
            else {
                if (right >= nums.size() - 1) {
                    left++;
                    right = left + 1;
                }
                else
                    right++;
            }
        }
        
        
        return res;
    }
};