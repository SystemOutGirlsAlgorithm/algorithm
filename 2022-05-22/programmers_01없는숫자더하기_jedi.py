def solution(numbers):
    answer = 45
    
    for number in numbers:
        answer -= number
    
    return answer