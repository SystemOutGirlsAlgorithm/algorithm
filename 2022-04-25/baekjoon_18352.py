import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

# 모든 도로의 거리는 1이기 때문에 인접한 노드만 추가해줘도 됨
for _ in range(m) :
    a, b = map(int, input().split())
    graph[a].append(b)

def solution(start) :
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    # q가 빌 때까지
    while q :
        dist, now = heapq.heappop(q)
        # q에 있는 값이 now번째 노드의 최단거리보다 크다면 이미 방문했기 때문에 넘어감
        # 기존에 최단거리를 INF로 정해놨기 때문에 INF가 아니면 방문한 노드
        if dist > distance[now] : 
            continue
        # 인접노드 모두 돌기
        for g in graph[now] :
            # 원래는 cost = g[0](도시 간 거리) + dist 이지만 
            # 문제에서 모든 도로의 거리가 1이라고 했으므로 1을 더해주면 됨
            cost = 1 + dist
            # 인접노드 간 계산한 최단 거리가 현재 최단 거리보다 작을 때
            if cost < distance[g] :
                # 최단 거리 변경
                distance[g] = cost
                # 큐에 넣어주기
                heapq.heappush(q, (cost, g))
solution(x)

# k가 최단거리 리스트에 있을 때만 
if k in distance :
    for i in range(1, n+1) :
        if distance[i] == k :
            print(i)
# 없다면 -1 출력
else :
    print(-1)