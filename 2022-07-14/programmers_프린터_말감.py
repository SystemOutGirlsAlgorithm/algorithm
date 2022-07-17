from collections import deque

def solution(priorities, location):
    answer = 1
    queue = deque()
    for p in range(len(priorities)) :
        queue.append([priorities[p], p])
    temp = sorted(priorities, reverse=True)
    while True :
        q = queue.popleft()
        if q[0] != temp[0] :
            queue.append(q)
            continue
        if q[1] == location :
            break
        temp = temp[1:]
        answer += 1
    return answer