# 1. Two Sum
# Worst Case : O(n^2)
# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         for i in range(len(nums)):
#             for j in range(i+1, len(nums)):
#                 if nums[i] + nums[j] == target:
#                     return [i, j]

# HashMap : O(n)
class Solution:
     def twoSum(self, nums: List[int], target: int) -> List[int]:
            diff = dict()
            for idx in range(len(nums)):
                diff[nums[idx]] = idx
            
            for i in range(len(nums)):
                if target - nums[i] in diff:
                    if diff[target - nums[i]] != i:
                        return [i, diff[target - nums[i]]]
                
