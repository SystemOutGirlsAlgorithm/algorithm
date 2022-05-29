# 88. Merge Sorted Array
# Merge Sort로 푸는 방법(Solution 참고)
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        while m > 0 and n > 0:
            if nums1[m - 1] > nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n - 1]
                n -= 1
        # nums1의 끝부터 채우다가
        # 1. m이 먼저 0이 되는 경우 : 남은 nums2 값들이 nums1보다 모두 작으므로 아래 식 성립
        # 2. n이 먼저 0이 되는 경우 : nums1[:0] = nums2[:0] 이므로 변화 없음
        nums1[:n] = nums2[:n]