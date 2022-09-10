n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
lst = []

def dfs(k):
    if len(lst) == m:
        print(*lst)
        return

    for i in range(k, n):
        if arr[i] not in lst:
            lst.append(arr[i])
            dfs(i+1)
            lst.pop()

dfs(0)