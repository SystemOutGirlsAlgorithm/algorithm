count = int(input())

lst = list(map(int, input().split()))

M = max(lst)

for i in range(len(lst)):
    lst[i] = (lst[i] / M) * 100

sum = 0

for i in range(len(lst)):
    sum += lst[i]

sum /= len(lst)

print(sum)