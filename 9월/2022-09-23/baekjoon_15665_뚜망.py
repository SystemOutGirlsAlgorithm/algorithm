N, M = map(int, input().split())
arr = sorted(set(map(int, input().split())))
visit = [0] * N
L = len(arr)

def f(i, lst):
    if i == M:
        print(*lst)
        return

    for j in range(L):
        f(i+1, lst+[arr[j]])

f(0, [])
