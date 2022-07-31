from collections import deque

def solution(s):
    answer = ''
    number = {'zero' : '0', 'one' : '1', 'two' : '2', 'three' : '3', 'four': '4', 'five' : '5', 'six' : '6', 'seven' : '7', 'eight' : '8', 'nine' : '9'}
    queue = deque(list(map(str, s)))
    while queue :
        q = queue.popleft()
        if q.isdigit() :
            answer += q
            continue
        while q not in number :
            q += queue.popleft()
        answer += number[q]
    return int(answer)
            