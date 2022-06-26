import sys
import heapq
input = sys.stdin.readline

n = int(input())
leftarr = []
rightarr = []

for i in range(n) :
    x = int(input())
    if i % 2 == 0 :
        heapq.heappush(leftarr, -x)
    else :
        heapq.heappush(rightarr, x)
    try :
        left = -leftarr[0]
        right = rightarr[0]
        if -leftarr[0] > rightarr[0] :
            heapq.heappop(leftarr)
            heapq.heappop(rightarr)
            heapq.heappush(leftarr, -right)
            heapq.heappush(rightarr, left)
        print(-leftarr[0])
    except :
        print(-leftarr[0])
