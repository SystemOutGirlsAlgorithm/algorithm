from collections import deque
import sys
input = sys.stdin.readline

m, n = map(int, input().split())

box = []
tomato = deque()

for i in range(n) :
    tmp = list(map(int, input().split()))
    for j in range(m) :
        if tmp[j] == 1 :
            tomato.append([i, j])
    box.append(tmp)

count = -1
while tomato :
    num = len(tomato) 
    for _ in range(num) :
        i, j = tomato.popleft()
        for p, q in ([-1, 0], [0, -1], [0, 1], [1, 0]) :
            if 0 <= i+p <= n-1 and 0 <= j+q <= m-1 : 
                if box[i+p][j+q] == 0 :
                    box[i+p][j+q] = 1
                    tomato.append([i+p, j+q])
    count += 1  

for i in range(n) :
    if 0 in box[i] :
        count = -1
        break

print(count)
