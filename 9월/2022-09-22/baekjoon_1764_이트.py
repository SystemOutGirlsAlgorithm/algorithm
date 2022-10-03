# 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M
n, m = map(int, input().split())
nn = set()
mm = set()

for _ in range(n):
    nn.add(input())

for _ in range(m):
    mm.add(input())
    
cnt = 0
dict_ = list()
for i in nn:
    if i in mm:
        cnt += 1
        dict_.append(i)

print(cnt)
for j in sorted(dict_):
    print(j)