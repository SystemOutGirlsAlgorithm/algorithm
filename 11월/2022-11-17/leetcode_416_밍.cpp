class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) sum += num;
        if (sum % 2 == 1) return false;
        else sum /= 2;
        
        vector<bool> dp(sum+1);
        dp[0] = true; //0
        for (auto num: nums) {
            for (int i = sum; i > 0; i--) {
                if (i >= num) dp[i] = dp[i] || dp[i - num];
                //현재 sum에서 num만큼을 뺐을 때 0이 되면 참
            }
        }
        
        return dp[sum];
    }
};