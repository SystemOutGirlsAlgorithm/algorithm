def f(lst, n):
    global ans
    if sum(lst) == n:
        ans += 1
        return
    
    for i in range(1, 4):
        if sum(lst)+i <= n:
            f(lst+[i], n)

for _ in range(int(input())):
    n = int(input())
    ans = 0

    f([], n)
    print(ans)