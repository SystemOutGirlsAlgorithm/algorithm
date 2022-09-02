def dfs(l, k):
    if l == k:
        print(*lst)
        return 
    
    for i in range(1, n+1):
        lst.append(i)
        dfs(l+1, k)
        lst.pop()


n, m = map(int, input().split())
lst = []

dfs(0, m)
