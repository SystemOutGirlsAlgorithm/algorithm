import sys
input = sys.stdin.readline
INF = int(1e9)

n = int(input())

graph = []

for _ in range(n) : 
    graph.append(list(input().strip()))

for i in range(n) :
    for j in range(n) :
        # N일 때
        if graph[i][j] == 'N' :
            # 다른 노드끼리 일 때는 INF
            if i != j :
                graph[i][j] = INF
            # 같은 노드 끼리면 0
            else :
                graph[i][j] = 0
        # Y일 때는 1
        else :
            graph[i][j] = 1


# 플로이드-워셜로 문제 풀기
for k in range(n) :
    for a in range(n) :
        for b in range(n) :
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

answer = 0
for i in range(n) :
    tmp = 0
    for j in range(n) :
        # 친구사이의 거리가 2이하일 때만
        if 0 < graph[i][j] <= 2 :
            tmp += 1
    answer = max(answer, tmp)

print(answer)