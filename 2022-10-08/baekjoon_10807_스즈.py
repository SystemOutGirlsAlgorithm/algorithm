import sys

n = int(input())
numbers = list(map(int,sys.stdin.readline().split()))
v = int(input())

# count = 0
#
# for i in range(n):
#     if numbers[i]==v:
#         count+=1
#
# print(count)
#
#

print(numbers.count(v))