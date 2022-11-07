class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size() - 1, mid;
        while (first < last) {
            mid = (first + last) / 2;
            if (nums[mid] > nums[last]) first = mid + 1;
            else last = mid;
        }
        
        int pivot = first, pvmid;
        first = 0;
        last = nums.size() - 1;
        while (first <= last) {
            mid = (first + last) / 2;
            pvmid = (mid + pivot) % nums.size();
            if (nums[pvmid] == target) return pvmid;
            else if (nums[pvmid] < target) first = mid + 1;
            else last = mid - 1;
        }
        return -1;
    }
};