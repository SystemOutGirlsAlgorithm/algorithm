cnt = int(input())

num = 0
while 1:
    if '666' in str(num): # 값을 찾았을 때만 카운팅
        cnt -= 1
        if cnt == 0:
            break
    num += 1
print(num)