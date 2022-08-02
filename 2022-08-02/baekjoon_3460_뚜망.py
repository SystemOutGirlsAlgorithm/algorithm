T = int(input())
for _ in range(T):
    li = []
    N = int(input())

    def binary(arr, n):
        m = n%2
        arr.append(m)
        if n == 0 or n == 1:
            return arr
        elif m:
            return binary(arr, n // 2)
        else:
            return binary(arr, n // 2)

    li = binary(li, N)

    for i, l in enumerate(li):
        if l:
            print(i, end=' ')
