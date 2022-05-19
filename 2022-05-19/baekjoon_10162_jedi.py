#baekjoon_10162_jedi.py
#Greedy

sec = int(input())

button = [0, 0, 0]
time = 0

button[0] = sec // 300
time = sec % 300
button[1] = time // 60
time = time % 60
button[2] = time // 10
time = time % 10

if time > 0:
    print(-1)
elif button[0]==0 and button[1]==0 and button[2] == 0:
    print(0)
else:
    print(button)

