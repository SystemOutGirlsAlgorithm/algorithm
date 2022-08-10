# 1212 : 8진수 2진수

result = []

for n in list(input()):
    two = list()
    n = int(n)
    for i in range(3):
        if n == 0:
            two.insert(0, '0')
            break
        two.insert(0, str(n % 2))
        n = int(n / 2)
    for i in range (3-len(two)):
        two.insert(0, '0')
    result.append(''.join(two))
result = ''.join(result)

for i in range(2):
    if result[0] == '0':
        result = result[1:]
print(result)