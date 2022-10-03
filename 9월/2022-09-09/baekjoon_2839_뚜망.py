n = int(input())

m = n // 3
for i in range(m+1):
    k = n-3*i
    if not k % 5:
        res = k//5 + i
        break
else:
    res = -1

print(res)