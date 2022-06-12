def solution(n):
    answer = []
    
    while n != 0 :
        answer.append(n%10)
        n = n // 10
    
    return answer