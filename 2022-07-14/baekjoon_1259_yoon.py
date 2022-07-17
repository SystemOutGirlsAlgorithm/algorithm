#백준 1259번

while True:
    n = input()
    
    if n=='0':
        break
    if n==n[::-1]:
        print('yes')
    else:
        print('no')
