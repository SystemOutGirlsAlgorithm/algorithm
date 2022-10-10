# 1로 만들기

N = int(input())
v = [0] * N

def one(N):
    queue = [(N, 0)]
    while queue:
        n, c = queue.pop(0)
        if not n % 3 and v[n // 3] == 0:
            if n // 3 == 1:
                return c + 1
            v[n // 3] = 1
            queue.append((n // 3, c + 1))
        if not n % 2 and v[n // 2] == 0:
            if n // 2 == 1:
                return c + 1
            v[n // 2] = 1
            queue.append((n // 2, c + 1))
        if n - 1 > 0 and v[n - 1] == 0:
            if n - 1 == 1:
                return c + 1
            v[n - 1] = 1
            queue.append((n - 1, c + 1))

if N == 1:
    print(0)
else : print(one(N))
