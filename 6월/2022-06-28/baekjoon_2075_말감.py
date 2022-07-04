import sys
import heapq

input = sys.stdin.readline

n = int(input())
max_arr = []

for _ in range(n) :
    arr = list(map(int, input().split()))
    for a in arr :
        if len(max_arr) < n :
            heapq.heappush(max_arr, a)
            continue
        if max_arr[0] < a :
            heapq.heappop(max_arr)
            heapq.heappush(max_arr, a)

print(max_arr[0])