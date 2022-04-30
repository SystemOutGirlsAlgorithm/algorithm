n, k = map(int, input().split())

bottle = 0

while bin(n).count('1') > k :
    i = bin(n)[::-1].index('1')
    n += (2**i)
    bottle += (2**i)

print(bottle)