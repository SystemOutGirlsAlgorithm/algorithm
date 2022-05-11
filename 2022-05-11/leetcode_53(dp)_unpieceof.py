# Array
# 53. Maximum Subarray
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # DP - 카데인 알고리즘
        for i in range(1, len(nums)):
            if nums[i - 1] > 0: #i-1의 수가 0보다 크면
                nums[i] += nums[i - 1] #i번째 수와 i-1의 수를 더해서 최댓값을 찾는다.
        return max(nums)
