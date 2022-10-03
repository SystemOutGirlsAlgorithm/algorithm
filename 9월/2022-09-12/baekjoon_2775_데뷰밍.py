t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())
    cnt = [i for i in range(1, n + 1)]

    
    for i in range(1, k + 1):
        temp = 0
        for j in range(n):
            temp += cnt[j]
            cnt[j] = temp

    print(cnt[n - 1])