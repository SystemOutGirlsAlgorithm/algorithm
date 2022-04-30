import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t) :
    n = int(input())
    person = []
    for _ in range(n) :
        person.append(list(map(int, input().split())))
    person.sort()
    
    rank = person[0][1]
    count = 1
    for i in range(1, len(person)) :
        if person[i][1] < rank :
            count += 1
            rank = person[i][1]
    print(count)