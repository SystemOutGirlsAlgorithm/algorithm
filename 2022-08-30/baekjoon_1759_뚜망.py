def dfs(k):
    if len(pwd) == l:
        cnt = vow = 0
        for p in pwd:
            if p in 'aeiou':
                cnt += 1
        if cnt >= 1 and l-cnt >= 2:
            print(''.join(pwd))

    for i in range(k, c):
        if alpha[i] not in pwd:
            pwd.append(alpha[i])
            dfs(i+1)
            pwd.pop()

l, c = map(int, input().split())
alpha = list(input().split())
alpha.sort()
pwd = []

dfs(0)