#baekjoon_5585_jedi.py

money = 1000 - int(input())

pm = [500, 100, 50, 10, 5, 1]
ans = 0

for i in pm:
    ans += money//i
    money %= i

print (int(ans))