T = int(input())

for test_case in range(T):
    n = int(input())
    cnt = 0
    while n:
        if n % 2:
            print(cnt, end=' ')
        n //= 2
        cnt += 1