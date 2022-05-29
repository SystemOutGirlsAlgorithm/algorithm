# Array
# 53. Maximum Subarray
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max = -10000
        tempsum = 0
        
        for num in nums:
            tempsum += num
            if tempsum > max:
                max = tempsum
            
            if tempsum < 0: #전부 음수인 경우도 커버가 되는지 확인 필요
                tempsum = 0
        
        return max
