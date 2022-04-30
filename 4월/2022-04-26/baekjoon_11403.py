import sys
input = sys.stdin.readline

INF = int(1e9)

n = int(input())

graph = []

for _ in range(n) :
    graph.append(list(map(int, input().split())))

for k in range(n) :
    for a in range(n) :
        for b in range(n) :
            if graph[a][b] == 0 :
                graph[a][b] = INF
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for i in range(n) :
    for j in range(n) :
        if graph[i][j] != INF :
            print(1, end=" ")
        else :
            print(0, end=" ")
    print()