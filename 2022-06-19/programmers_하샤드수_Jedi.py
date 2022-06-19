def solution(x):
    answer = False
    num = x
    sum = 0
    
    while x != 0:
        sum += x%10
        x //= 10
    
    if num%sum == 0:
        answer = True
    
    return answer