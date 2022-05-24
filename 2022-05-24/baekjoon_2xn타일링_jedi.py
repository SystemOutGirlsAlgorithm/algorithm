ds = [0] * 1001
ds[1], ds[2] = 1, 2

for i in range(3, 1001):
    ds[i] = ds[i-1] + ds[i-2]

n = int(input())
print(ds[n]%10007)