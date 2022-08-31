def dfs(v):# 시작점
    vi[v] = 1
    print(v, end=' ')
    for d in node[v]:
        if vi[d] == 0:
            dfs(d)
    return

def bfs(v):
    q.append(v)
    vi[v] = 1
    while q:
        t = q.pop(0)
        print(t, end=' ')
        for s2 in node[t]:
            if vi[s2] == 0:
                q.append(s2)
                vi[s2] = 1


n, m, v = map(int, input().split())
node = [[] for _ in range(n+1)]
vi = [0] * (n+1)
q = []

for _ in range(m):
    a, b = map(int, input().split())
    node[a].append(b)
    node[b].append(a)

for d in node:
    d.sort()

dfs(v)
print()
vi = [0] * (n+1)
bfs(v)
print()