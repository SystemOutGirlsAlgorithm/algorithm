# 387. First Unique Character in a String
from collections import Counter

class Solution:
    def firstUniqChar(self, s: str) -> int:
        s_cnt = Counter(s)
        for i in range(len(s)):
            if s_cnt[s[i]] == 1:
                return i
        return -1
        