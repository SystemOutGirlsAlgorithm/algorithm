T = int(input())
for test_case in range(1, T + 1):
    _ = input()
    arr = list(map(int, input().split()))
    max, min = arr[0], arr[0]

    # max
    for M in arr:
        max = M if max < M else max
    # min
    for m in arr:
        min = m if min > m else min

    print(f'#{test_case} {max-min}')