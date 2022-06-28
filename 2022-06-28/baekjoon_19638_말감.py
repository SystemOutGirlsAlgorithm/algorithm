import sys
import heapq

input = sys.stdin.readline

n, h, t = map(int, input().split())

height = []
count = 0
for _ in range(n) :
    heapq.heappush(height, -int(input()))

for _ in range(t) :
    if -height[0] == 1 or -height[0] < h :
        break
    tmp_h = -heapq.heappop(height)
    if tmp_h > 1 :
        heapq.heappush(height, -(tmp_h/2))
    else :
        heapq.heappush(height, -1)
    count+=1

if -height[0] < h :
    print('YES')
    print(count)
else :
    print('NO')
    print(int(-height[0]))