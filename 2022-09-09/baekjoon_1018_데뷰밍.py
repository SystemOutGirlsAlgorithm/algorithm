n, m = map(int, input().split())
board = []
for _ in range(n):
    board.append(list(input()))   # B : 검정, W : 흰색

color = ["B", "W"]
result = 2501

for i in range(0, n - 8 + 1):
    for j in range(m - 8 + 1):
        for c in color:
            now = c
            count = 0
            for x in range(i, i + 8):
                for y in range(j, j + 8):
                    if now != board[x][y]:
                        count += 1
                    
                    now = "W" if now == "B" else "B"

                now = "W" if now == "B" else "B"
                
            result = min(result, count)

print(result)