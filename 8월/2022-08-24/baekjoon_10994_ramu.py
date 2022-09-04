# 10994 : 별 찍기 - 19
N = int(input())
n = 0
Nlist = []
while(n < N):
    n += 1
    li = list('*' for _ in range(4 * n - 3))
    Nlist.insert(0, li)
    if n > 1:
        Nlist.insert(1, ['*'] + [' ' for _ in range(4 * n - 5)] + ['*'])
        for i in range(2, len(Nlist)):
            Nlist[i] = ['*', ' '] + Nlist[i]
            Nlist[i] = Nlist[i] + [' ', '*']
if N != 1:
    for i in range(2 * N - 3, 0, -1):
        Nlist.append(Nlist[i])
    Nlist.append(Nlist[0])

for i in Nlist:
    print(*i, sep='')