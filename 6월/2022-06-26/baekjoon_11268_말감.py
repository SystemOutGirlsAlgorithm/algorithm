import heapq
import sys
input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n) :
    x = int(input())
    if x != 0 :
        heapq.heappush(arr, (abs(x), x))
        continue
    if len(arr) == 0 :
        print(0)
        continue
    min_value = heapq.heappop(arr)
    print(min_value[1])
