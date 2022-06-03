# 383. Ransom Note
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(Counter(ransomNote) - Counter(magazine)) == 0:
            return True