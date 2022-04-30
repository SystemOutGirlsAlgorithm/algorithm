import sys
from collections import deque
input = sys.stdin.readline

m, n, h = map(int, input().split())

box = []
tomato = deque()
empty = 0

# box에 전체 토마토 저장
for i in range(h) :
    box_tmp = []
    for j in range(n) :
        tmp = list(map(int, input().split()))
        box_tmp.append(tmp)
        for k in range(m) :
            # 토마토가 익어있으면 tomato에 append
            if tmp[k] == 1 :
                tomato.append([i, j, k])
            # 토마토가 없으면 empty + 1
            elif tmp[k] == -1 :
                empty += 1
    box.append(box_tmp)

# 토마토 익히기
def solution() :
    count = 0
    while tomato :
        num = len(tomato)
        for _ in range(num) :
            a, b, c = tomato.popleft()
            for p, q, r in ([-1, 0, 0], [1, 0, 0], [0, 0, -1], [0, -1, 0], [0, 0, 1], [0, 1, 0]) :
                if 0 <= a+p < h and 0 <= b+q < n and 0 <= c+r < m :
                    if box[a+p][b+q][c+r] == 0 :
                        box[a+p][b+q][c+r] = 1
                        tomato.append([a+p, b+q, c+r])
        count += 1
    return count

# 익은 토마토가 없을 경우 -1 출력    
if len(tomato) == 0 :
    print(-1)
# 빈 공간을 제외하고 모든 토마토가 익어있을 경우 0 출력
elif len(tomato) + empty == m*n*h :
    print(0) 
else :
    cnt = solution()
    for i in range(h) :
        for j in range(n) :
            # 토마토가 모두 익지 못하는 상황
            if 0 in box[i][j] :
                print(-1)
                exit(0)
    # 토마토가 모두 익었을 경우
    print(cnt-1)  