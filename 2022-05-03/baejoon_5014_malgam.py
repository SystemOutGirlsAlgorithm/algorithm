from collections import deque
import sys
input = sys.stdin.readline

f, s, g, u, d = map(int, input().split())
floor = [0] * (f+1)

def solution(s) : 
    queue = deque()
    queue.append(s)
    while queue :
        q = queue.popleft()
        if q == g :
            return floor[q]
        for tmp in (q+u, q-d) :
            if 0 < tmp <= f and floor[tmp] == 0 and tmp != s :
                queue.append(tmp)
                floor[tmp] = floor[q] + 1
    return "use the stairs"

print(solution(s))

