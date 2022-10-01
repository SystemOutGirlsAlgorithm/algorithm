n,k = map(int,input().split())
temp = list(map(int, input().split()))

added = sum(temp[:k])
result = [added]

for i in range(n-k):
    added = added-temp[i]+temp[i+k]
    result.append(added)

print(max(result))

