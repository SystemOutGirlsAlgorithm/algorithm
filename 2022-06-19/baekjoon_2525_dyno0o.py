h, m = map(int, input().split())
t = int(input())
time = 60*h + m + t
H, M = divmod(time, 60)
H = H % 24
print(H, M)
