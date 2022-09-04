n, m = map(int, input().split())
lst = []

def bT(k, m):
    if len(lst) == m:
        print(*lst)
        return
    
    for i in range(k, n+1):
        lst.append(i)
        bT(i, m)
        lst.pop()

bT(1, m)