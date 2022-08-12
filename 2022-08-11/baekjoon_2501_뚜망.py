n, k = map(int, input().split())
cnt = 0

for i in range(1, n+1):
    if not n % i:
        cnt += 1
        if cnt == k:
            print(i)
            break
else:
    print(0)