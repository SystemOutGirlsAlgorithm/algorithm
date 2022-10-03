from collections import deque

def solution(numbers, target):
    answer = 0
    
    n = len(numbers)
    
    queue = deque()
    queue.append([numbers[0], 0])
    queue.append([-numbers[0], 0])
    
    while queue:
        tmp, idx = queue.popleft()
        idx += 1
        
        if idx < n:
            queue.append([tmp + numbers[idx], idx])
            queue.append([tmp - numbers[idx], idx])
        
        elif tmp == target:
            answer += 1
    return answer