import sys
sys.stdin = open('test.txt')

def bfs(start):
    global time
    queue = [start]
    visit = [[0] * N for _ in range(N)] # bfs로 탐험하면서 이미 방문했던 위치는 두 번 방문할 이유 X
    select = (N, N)
    min_d = 1e9
    while queue:
        si, sj = queue.pop(0)
        for di, dj in ((-1, 0), (0, -1), (1, 0), (0, 1)):
            ni, nj = si + di, sj + dj 
            if -1 < ni < N and -1 < nj < N and visit[ni][nj] == 0:
                visit[ni][nj] = visit[si][sj] + 1
                # 먹을 물고기를 찾았다면 더 이상 물고기를 탐험할 필요가 없다
                # 같은 거리의 물고기들을 다 찾았다면 그때의 min_d로 값이 설정되어 있기 때문에
                # 그 위치에서 다음 위치로 탐험을 시작하려고 하면 바로 break로 반복문 탈출
                if visit[ni][nj] > min_d:
                    break
                # 지나갈 수 있는 위치(0이거나 size인 경우) -> append
                if arr[ni][nj] == 0 or arr[ni][nj] == size:
                    queue.append((ni, nj))
                # 먹을 수 있는 물고기(size보다 작은 경우) -> 그 중에서 가장 위 왼쪽에 있는 거 골라서 start에 다시
                elif arr[ni][nj] < size:
                    min_d = visit[ni][nj]
                    select = min(select, (ni, nj))

    # 먹을 물고기가 결정되었다면(select가 있다면) time에 이동거리(min_d)만큼 더해주고 (1칸 = 1초)
    # return으로 함수 종료
    # 반드시 select가 결정되었을 경우에만 time값 추가
    if select == (N, N):
        return (-1, -1)
    time += min_d
    return select

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
size, eat, time = 2, 0, 0

# 상어의 현재 위치(start)와 물고기의 개수(fish) 찾기
fish = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 9:
            arr[i][j] = 0
            start = (i, j)
        elif arr[i][j]:
            fish += 1

# 상어의 위치부터 시작해서 탐험
# 물고기가 있을 경우에만 이동
while fish:
    start = bfs(start)
    # 더 이상 탐험할 물고기가 없었다면 (-1, -1)이 반환
    # 그냥 (N, N)으로 해도 됨 
    if start == (N, N):
        break
    fish -= 1
    eat += 1
    if eat == size:
        size += 1
        eat = 0

print(time)