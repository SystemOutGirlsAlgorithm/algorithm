def solution(n):

    num = 0
    
    while True:
        if num*num == n:
            return (num+1)*(num+1)
        if num*num > n:
            return -1
        num += 1
