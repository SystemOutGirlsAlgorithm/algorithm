n = int(input())

result = 0
i = 1
now = 666

while i <= n:
    if "666" in str(now):
        result = now
        i += 1
        
    now = now + 1

print(result)