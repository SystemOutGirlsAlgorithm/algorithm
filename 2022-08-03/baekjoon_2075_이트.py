## 2075 N번째 큰 수
## https://www.acmicpc.net/problem/2075
## 메모리 초과...

import heapq
import sys

input = sys.stdin.readline
N = int(input())

heap = []

for _ in range(N):
    nums = list(map(int, input().split()))

    if not heap: 
        for num in nums:        # 초기 nums만큼 배열에 push
            heapq.heappush(heap,num)
    else:
        for num in nums:        # 배열 사이즈를 동일하게 하기 위해 push하고 pop
            if heap[0] < num:
                heapq.heappush(heap,num)
                heapq.heappop(heap)
    
print(heap[0])                  # 정렬이 되어 있으므로 인덱스 0을 불러옴