n, m = map(int, input().split())
lst = [[] for _ in range(n+1)]
maxV, res = -1, []

for _ in range(m):
    a, b = map(int, input().split())
    lst[b].append(a)

for i in range(1, n+1):
    visit = [0] * (n+1)
    if lst[i]:
        cnt = 1
        visit[i] = 1
        stack = [i]

        while stack:
            sti = stack.pop()
            for j in lst[sti]:
                if not visit[j]:
                    visit[j] = 1
                    cnt += 1
                    stack.append(j)

        if maxV < cnt:
            maxV = cnt
            temp = [i]
        elif maxV == cnt:
            temp.append(i)

print(*temp)