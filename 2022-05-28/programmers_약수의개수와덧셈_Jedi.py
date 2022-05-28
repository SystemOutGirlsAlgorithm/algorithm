
left = 13
right = 17

answer = 0

for i in range(left, right+1):
    prime = 0
    for j in range(1, i+1):
        if i % j == 0:
            prime += 1
    
    if prime % 2 == 0:
        answer += i
    else:
        answer -= i
