total = []
result = []

def d(num):
    sum=num
    while(num!=0): 
        sum = sum + (num%10)
        num = num//10
    return sum


for i in range(1, 10001):
    total.append(d(i))

total = sorted(set(total))

for i in range(1, 10001):
    if i not in total:
        result.append(i)
print(result)
