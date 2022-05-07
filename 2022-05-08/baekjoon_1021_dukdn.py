from collections import deque
import sys

input=sys.stdin.readline

#N은 큐의 크기 M은 뽑아내려고하는 개수
N,M=map(int, input().split())
idxs =list(map(int,input().split()))
d = deque([i for i in range(1,N+1)])

count=0
for idx in idxs:
  while True:
    if d[0]==idx:
      d.popleft()
      break
    else:
      if d.index(idx) < len(d)/2:
        while d[0] != idx:
          d.append(d.popleft())
          count += 1
      else:
        while d[0] != idx:
          d.append(d.pop())
          count += 1
print(count)
          