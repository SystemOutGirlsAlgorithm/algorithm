def solution(n):
    num=set(range(2,n+1)) # 2부터 n+1까지의 집합

    for i in range(2,n+1): # 2부터 n까지 반복문
        if i in num: # 만약 i가 num 집합에 있다면
            num-=set(range(2*i,n+1,i)) # i의 배수는 num 집합에서 제외
    return len(num) # num에 남아있는 숫자의 개수가 소수의 개수