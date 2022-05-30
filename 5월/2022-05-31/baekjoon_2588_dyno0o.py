a = int(input())
b = int(input())

list_a = list(map(int, str(a)))
list_b = list(map(int, str(b)))

print(a * list_b[-1])
print(a * list_b[1])
print(a * list_b[0])
print(a * b)
