import sys
input = sys.stdin.readline

n = int(input())

times = []

for _ in range(n) :
    times.append(list(map(int, input().split())))

times.sort()
times = sorted(times, key=lambda x:x[1])

start = times[0][1]

count = 1
for i in range(1, n) :
    if start <= times[i][0] :
        count += 1
        start = times[i][1]

print(count)