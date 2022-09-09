# 백준_7568_덩치
n = int(input())
size = []
grade = [1] * n

for _ in range(n):
    size.append(list(map(int, input().split())))


for i in range(n):
    for j in range(n):
        if i == j :
            continue
        if size[i][0] < size[j][0] and size[i][1] < size[j][1]:
            grade[i] += 1

for g in grade:
    print(g, end=' ')