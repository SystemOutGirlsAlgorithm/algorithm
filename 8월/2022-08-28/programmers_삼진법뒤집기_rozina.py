def solution(n):
    answer = 0
    n3 = ''
    while n>0:
        n3 += str(n%3)
        n = n//3
    
    for aa in range(len(n3)):
        answer += int(n3[aa]) * (3**(len(n3)-1-aa))
    
    return answer
