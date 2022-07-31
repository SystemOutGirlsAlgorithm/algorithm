#baekjoon_1110_yoon.py


n = int(input())
num = n
cnt = 0

while True:
    a = num // 10    #a는 10의 자리수
    b = num % 10     #b는 1의 자리수
    c = (a+b) % 10    #c는 각 자리수를 더한 값에서 1의 자리수
    
    num = (b*10) + c    #기존값num의 1의 자리수를 10의자리수로, 더한값c를 1의자리수로
    
    cnt = cnt + 1    
    if(num==n):    #입력값과 중복되는지 검사 맞다면 break
        break

print(cnt)
