n = int(input())
count = 0

for _ in range(n):
    value = input()
    dic = {}
    count += 1
    
    for i, v in enumerate(value):
        if dic.get(v, 0) != 0 and value[i-1] != v:
            count -= 1
            break
        dic[v] = dic.get(v, 0) + 1

print(count)