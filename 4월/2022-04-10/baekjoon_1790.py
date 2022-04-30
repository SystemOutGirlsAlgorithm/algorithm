n, k = map(int, input().split())

# 수의 길이 알아내기
lng = 0
for i in range(len(str(n))) :
    if i < len(str(n))-1 :
        lng += 9 * (10**i) * (i+1)
    else :
        lng += (n - (10**i) + 1) * len(str(n))
        
def solution() : 
    if lng < k :
        print(-1)
        return
    if k < 10 :
        print(k)
        return
    a = 0
    for i in range(len(str(n))) :
        a = 9 * (10**i) * (i+1) + a
        b = 9 * (10**(i+1)) * (i+2)
        if a < k <= a + b :
            # 1을 빼는 이유 :
            # 배열은 0부터 시작하기 때문
            tmp = k - a - 1
            number = 10 ** (i+1) + (tmp // (i+2))
            rest = tmp % (i+2)
            print(str(number)[rest])
            return

solution()