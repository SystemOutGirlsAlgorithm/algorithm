import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

def solution(start, conv, end) :
    visited = [0] * n
    queue = deque()
    queue.append(start)
    while queue :
        s = queue.popleft()
        if abs(s[0] - end[0]) + abs(s[1] - end[1]) <= 1000 :
            print("happy")
            return
        for i in range(n) :
            p, q = conv[i]
            if abs(s[0] - p) + abs(s[1] - q) <= 1000 and visited[i] == 0 :
                visited[i] = 1
                queue.append([p, q])
    print("sad")
    return

for _ in range(t) :
    n = int(input())

    start = list(map(int, input().split()))
    conv = [] 
    for _ in range(n) :
        conv.append(list(map(int, input().split())))
    end = list(map(int, input().split()))
    
    solution(start, conv, end)