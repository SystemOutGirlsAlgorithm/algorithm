# 350. Intersection of Two Arrays II
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        for i in range(len(nums1)):
            if len(nums2) == 0: return answer
            for j in range(len(nums2)):
                if nums1[i] == nums2[j]:
                    answer.append(nums1[i])
                    nums2.remove(nums1[i])
                    break
        return answer
                    
