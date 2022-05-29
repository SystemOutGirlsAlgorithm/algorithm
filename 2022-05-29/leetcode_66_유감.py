# 66. Plus One
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num_digit = int(''.join(map(str,digits)))
        num_digit+=1
        return list(str(num_digit))