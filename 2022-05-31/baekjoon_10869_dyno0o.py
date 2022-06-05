def operation(a, b):
  print(a + b) # 덧셈
  print(a - b) # 뺄셈
  print(a * b) # 곱셈
  
  if b!=0:
    # print(a / b) # 나눗셈
    print(a // b) # 몫
    print(a % b) # 나머지
  else:
    print('b!=0')

a, b = map(int, input().split())
operation(a, b)
