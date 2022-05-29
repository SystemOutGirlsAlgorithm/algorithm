def solution(a, b):
    answer = 0
    
    ma = max(a,b)
    mi = min(a,b)
    
    for i in range(mi, ma+1):
        answer += i
    
    return answer