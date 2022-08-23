# 숫자의 개수
num = 1
for _ in range(3):
    num *= int(input())

lst = [0] * 10
while num:
    lst[num%10] += 1
    num //= 10

print('\n'.join(map(str,lst)))