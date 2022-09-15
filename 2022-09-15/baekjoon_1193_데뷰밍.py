x = int(input())

cnt = 0
line = 0
while cnt < x:
    line += 1
    cnt += line

m = cnt - x # 라인에서 몇번째
if line % 2 == 0:
    i = line - m
    j = m + 1
else:
    i = m + 1
    j = line - m

print(f'{i}/{j}')