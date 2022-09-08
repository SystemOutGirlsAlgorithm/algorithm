import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)
n,m = map(int,input().split())
graph = [ [] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
    

v1,v2 = map(int,input().split())

def dijkstra(start,end):
    distance = [INF] * (n+1) 
    q=[]
    distance[start]=0
    heapq.heappush(q,(0,start))
    
    while q:
        dist,node = heapq.heappop(q)
        
        if distance[node]<dist:
            continue
        
        for next in graph[node]:
            cost = distance[node]+next[1]
            if cost < distance[next[0]]:
                distance[next[0]]=cost
                heapq.heappush(q,(cost,next[0]))
                
    return distance[end]

result =min(dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,n),dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,n)) 
if result < INF:
    print(result)
else:
    print(-1)         

