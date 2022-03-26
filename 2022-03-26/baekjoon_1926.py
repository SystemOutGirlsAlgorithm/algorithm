from collections import deque
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

paper = []
for _ in range(n) :
  paper.append(list(map(int, input().split())))

answer = []
# 상하좌우
position = [[-1,0], [1,0], [0,-1], [0,1]]
for i in range(n) :
  for j in range(m) :
    if paper[i][j] == 1 :
      count = 1
      # 방문하면 -1로
      paper[i][j] = -1
      queue = deque()
      queue.append([i, j])
      while queue :
        q = queue.popleft()
        for p in position :
          a = q[0] + p[0]
          b = q[1] + p[1]
          # 그림 범위 내에 있어야 하고, 1일 때
          if 0 <= a <= n-1 and 0 <= b <= m-1 and paper[a][b] == 1:
            count += 1
            paper[a][b] = -1
            queue.append([a, b])
      # 완료되면 anaswer에 넣음
      answer.append(count)

print(len(answer))
if len(answer) > 0 :
  print(max(answer))
else :
  print(0)