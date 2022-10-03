import sys

n = int(sys.stdin.readline().rstrip())
nums = [0] * 10001
for _ in range(n):
    nums[int(sys.stdin.readline().rstrip())] += 1

for i in range(1, len(nums)):
    for j in range(nums[i]):
        print(i)