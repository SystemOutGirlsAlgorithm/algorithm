n = int(input())

score = list(map(int, input().split()))

m = 0
for s in score:
    if s >= m:
        m = s

mean = 0
for s in score:
    s = s / m * 100
    mean += s

mean = mean / n

print(mean)
