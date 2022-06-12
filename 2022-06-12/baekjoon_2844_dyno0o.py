H, M = map(int, input().split())

if M > 44:
    print(H, M-45)
elif M < 45 and H >0:
    print(H-1, M+15)
else:
    print(23, M+15)
