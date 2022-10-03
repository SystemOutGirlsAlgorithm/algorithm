import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())
start = int(input())
INF = int(1e9)

distance = [INF] * (n+1)
graph = [ [] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    
    
    
def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    
    while q:
        dist,node = heapq.heappop(q)
        if distance[node] <dist:
            continue
        
        for next in graph[node]:
            cost = distance[node]+next[1]
            if cost < distance[next[0]]:
                distance[next[0]]=cost
                heapq.heappush(q,(cost,next[0]))
                
dijkstra(start)

for i in range(1,n+1):
    if distance[i]==INF:
        print('INF')
    else:
        print(distance[i])