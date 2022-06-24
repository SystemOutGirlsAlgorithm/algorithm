from itertools import combinations

def isprime(num):
    
    for i in range(2, num):
        if num % i == 0:
            return False
    
    return True

def solution(nums):
    answer = 0

    combi = list(combinations(nums, 3))
    
    for com in combi:
        if isprime(sum(com)):
            answer += 1        

    return answer