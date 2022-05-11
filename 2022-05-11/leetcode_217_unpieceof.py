# Array
# 217. Contains Duplicate
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        chk_dict = dict()
        for num in nums:
            try:
                if chk_dict[num] == 1:
                    return True
            except:
                chk_dict[num] = 1
        
        return False
