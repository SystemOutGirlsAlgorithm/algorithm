L = int(input())
lst = sorted(list(map(int, input().split())) + [0])
N = int(input())

cnt = 0
for l in range(L):
    if N in range(lst[l], lst[l+1]):
        a, b = lst[l], lst[l+1]
        break
        
for i in range(a+1, b-1):
    for j in range(a+2, b):
        if i != j and N in range(i, j+1):
            cnt += 1

print(cnt)