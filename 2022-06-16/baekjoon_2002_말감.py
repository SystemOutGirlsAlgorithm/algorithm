n = int(input())

start = []
answer = 0
for _ in range(n) :
    start.append(input())

for _ in range(n) :
    car = input()
    if car == start[0] :
        start = start[1:]
        continue
    answer += 1
    start.remove(car)

print(answer)
