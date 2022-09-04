n, m = map(int, input().split())
seq = sorted(list(map(int, input().split())))
lst = []

def bT(k, m):
    if k == m:
        print(*lst)
        return
    
    for s in seq:
        if s not in lst:
            lst.append(s)
            bT(k+1, m)
            lst.pop()

bT(0, m)