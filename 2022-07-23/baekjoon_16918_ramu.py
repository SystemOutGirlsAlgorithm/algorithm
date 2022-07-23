import sys
R, C, N = map(int, sys.stdin.readline().split())
graph = [list(sys.stdin.readline().strip()) for _ in range(R)]


def bomb(graph, N):
    if N == 1:
        return graph
    elif N % 2 == 0:
        return list(['O' for _ in range(C)] for _ in range(R))
    elif N % 4 == 3:
        graph2 = list(['O' for _ in range(C)] for _ in range(R))
        bombArr = []
        xArr = [0, 0, 0, 1, -1]
        yArr = [0, 1, -1, 0, 0]
        for i in range(R):
            for j in range(C):
                if graph[i][j] == 'O':
                    bombArr.append((i, j))
        for (x, y) in bombArr:
            for i in range(5):
                nx = x + xArr[i]
                ny = y + yArr[i]
                if (nx < 0 or ny < 0 or nx == R or ny == C):
                    continue
                graph2[nx][ny] = '.'
        return graph2
    elif N != 1 and N % 4 == 1:
        graph3 = bomb(graph, 3)
        return bomb(graph3, 3)
        
graph_result = bomb(graph, N)
for i in graph_result:
    print(*i, sep="")