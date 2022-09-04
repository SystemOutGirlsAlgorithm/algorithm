# 1064 : 평행사변형

import sys
coors = list(map(int, sys.stdin.readline().split()))
tri = []
result = []

for i in range(3):
    tri.append((coors[2*i], coors[2*i + 1]))

tri.sort(key = lambda x: -x[0])

for i in range(3):
    a, b = tri[i%3]
    m, n = tri[(i+1)%3]
    x, y = tri[(i+2)%3]
    if a == m == x or b == n == y:
        result = []
        break
    xx1, yy1 = (a-m), (b-n)
    xx2, yy2 = (m-x), (n-y)
    if yy1 != 0 and yy2 != 0 and xx1/yy1 == xx2/yy2:
        result = []
        break
    res1 = 2 * ((a-m)**2 + (b-n)**2)**(1/2)
    res2 = 2 * ((a-x)**2 + (b-y)**2)**(1/2)
    
    result.append(res1+res2)

if len(result) > 0:
    print(max(result) - min(result))
else:
    print(-1.0)