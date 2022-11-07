class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size()-1, mid;
        
        while (first <= last) {
            mid = (first+last) / 2;
            if (target > nums[mid])
                first = mid + 1;
            else if (target == nums[mid])
                return mid;
            else
                last = mid - 1;
        }
        return -1;
    }
};