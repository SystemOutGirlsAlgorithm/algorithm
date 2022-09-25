import sys
import heapq


input = sys.stdin.readline


v,e = map(int, input().split())
parent= []
for i in range(1,v+1):
    parent[i]=i
    

def find_parent(parent,x):
    if parent[x] == x:
        return x
    parent[x] = find_parent(parent,parent[x])
    return parent[x]
    


def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)
    
    if a<b:
        parent[b]=a
    else:
        parent[a]=b
        
edges=[]
total=0

for _ in range(e):
    a,b,cost=map(int,input().split())
    edges.append((cost,a,b))
    
edges.sort()

for i in range(e):
    cost,a,b = edges[i]
    if find_parent(parent,a) != find_parent(parent,b):
        total += cost
        union_parent(parent,a,b)
        
print()