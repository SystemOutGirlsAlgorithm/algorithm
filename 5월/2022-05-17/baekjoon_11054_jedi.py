num = int(input())
A = list(map(int, input().split()))
reA = A[::-1]

incr = [1] * num
decr = [1] * num

for i in range(num):
    for j in range(i):
        if A[i] > A[j]:
            incr[i] = max(incr[i], incr[j]+1)
        if reA[i] > reA[j]:
            decr[i] = max(decr[i], decr[j]+1)

result = [0] * num
for i in range(num):
    result[i] = incr[i] + decr[num-i-1] -1

print(max(result))