n = int(input())
value = int(input())

sum = 0

while(value != 0):
    sum += value%10
    value //= 10

print(sum)