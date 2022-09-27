# 백준_2751_수 정렬하기 2
import sys
n = int(sys.stdin.readline().rstrip())
nums = []
for _ in range(n):
    nums.append(int(sys.stdin.readline().rstrip()))

nums.sort()

for n in nums:
    print(n)