tc = int(input())
for _ in range(tc):
    a, b = map(int, input().split())

    multi = a * b
    while a % b:
        a, b = b, a % b
        
    print(multi // b)