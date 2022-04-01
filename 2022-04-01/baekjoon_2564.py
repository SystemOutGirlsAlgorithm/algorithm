import sys
input = sys.stdin.readline

m, n = map(int, input().split())
s = int(input())
point = []
for _ in range(s + 1) :
    a, b = map(int, input().split())
    if a == 1 :
        point.append([0, b])
    elif a == 2 :
        point.append([n, b])
    elif a == 3 : 
        point.append([b, 0])
    elif a == 4 :
        point.append([b, m])
   
dong = point[-1]
answer = 0

for i in range(len(point)-1) :
    if point[i][0] in (0, n) :
        if dong[0] in (0, n) :
            # 같은 라인에 있을 때
            if dong[0] == point[i][0] :
                answer += abs(dong[1] - point[i][1])
            # 서로 마주보고 있을 때
            else :
                answer += n + min(dong[1] + point[i][1], m - dong[1] + m - point[i][1])
        else :
            answer += abs(point[i][0] - dong[0]) + abs(point[i][1] - dong[1])
    else :
        if dong[1] in (0, m) :
            # 같은 라인에 있을 때
            if dong[1] == point[i][1] :
                answer += abs(dong[0] - point[i][0])
            # 서로 마주보고 있을 때
            else :
                answer += m + min(dong[0] + point[i][0], n - dong[0] + n - point[i][0])
        else :
            answer += abs(point[i][0] - dong[0]) + abs(point[i][1] - dong[1])
print(answer)