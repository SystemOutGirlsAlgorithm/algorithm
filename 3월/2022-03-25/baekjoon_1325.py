from collections import deque
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

computer = [[] for _ in range(n+1)]

for _ in range(m) :
    a, b = map(int, input().split())
    # A가 B를 신뢰할 때, B를 해킹하면 A도 해킹할 수 있다
    # = B 하위에 A가 있음
    computer[b].append(a)

answer = [0] * (n+1)
for i in range(1, n+1) : 
	# 해당 컴퓨터 하위에 있는 컴퓨터가 없을 땐 넘어가기
    if len(computer[i]) == 0 :
        continue
    visited = [False] * (n+1)
    queue = deque([i])
    visited[i] = True
    cnt = 1
    # BFS 사용
    while queue : 
        q = queue.popleft()
        for c in computer[q] :
            if visited[c] == False:
                visited[c] = True
                queue.append(c)
                cnt += 1
    answer[i] = cnt

tmp = []
for j in range(1, n+1) :
    if max(answer) == answer[j] :
        tmp.append(str(j))

print(*tmp)