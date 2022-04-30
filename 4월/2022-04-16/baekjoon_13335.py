import sys
from collections import deque
input = sys.stdin.readline

n, w, l = map(int, input().split())

truck = list(map(int, input().split()))

queue = [0] * w
queue = deque(queue)

answer = 0
for t in truck :
    while True :
        queue.popleft()
        answer += 1
        if sum(queue) + t > l :
            queue.append(0)
            continue
        else :
            queue.append(t)
            break
answer += w
print(answer)