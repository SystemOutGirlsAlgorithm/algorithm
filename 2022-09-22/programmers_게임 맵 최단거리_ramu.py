from collections import deque

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
def solution(maps):
    answer = 0
    cnt = 101
    queue = deque([(0, 0)])
    maps[0][0] = cnt
    m, n = len(maps[0]), len(maps)
    while queue:
        cnt += 1
        (y, x) = queue.popleft()
        for i in range(4):
            dx, dy = x + dir[i][1], y + dir[i][0]
            if 0 <= dx < m and 0 <= dy < n:
                if maps[dy][dx] == 1:
                    queue.append((dy,dx))
                    maps[dy][dx] = maps[y][x] + 1
    if maps[n-1][m-1] == 1:
        answer = -1
    else:
        answer = maps[n-1][m-1] - 100
    
    return answer