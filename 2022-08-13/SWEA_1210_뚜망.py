import sys
sys.stdin = open('SWEA_1210_ladder1.txt')
# 상 좌 우
dx = [-1, 0, 0]
dy = [0, -1, 1]

# 이동하고 싶은 칸에 값이 존재하는가를 판단하는 함수
def nav(x, y, idx=0):
    x += dx[idx]
    y += dy[idx]
    if 0 <= x < 100 and 0 <= y < 100 and arr[x][y] == 1:
        return idx
    else:
        return 0

for _ in range(10):
    tc = input()
    arr = [list(map(int, input().split())) for _ in range(100)]
    x = 98

    for i in range(100):
        if arr[99][i] == 2:
            y = i
            break
    
    idx = 0
    # 길 찾기
    while 1:
        # 최상단에 도달하면 탈출
        if x == 0:
            break
        # 위로 올라갈 때 
        if idx == 0:
            if nav(x, y, 1):
                idx = 1
            elif nav(x, y, 2):
                idx = 2
        # 좌우로 이동하고 있을 때, idx = 1 or 2
        # 더 이상 1이 없으면 
        else:
            if idx == 1:
                idx = nav(x, y, 1)
            elif idx ==2:
                idx = nav(x, y, 2)
        x += dx[idx]
        y += dy[idx]


    print('#%s %d' %(tc, y))
    