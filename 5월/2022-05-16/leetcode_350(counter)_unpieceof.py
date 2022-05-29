# 350. Intersection of Two Arrays II

from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        cnt_nums1 = Counter(nums1)

        for num in nums2:
            if cnt_nums1[num] > 0:
                answer.append(num)
                cnt_nums1[num]-=1

        return answer