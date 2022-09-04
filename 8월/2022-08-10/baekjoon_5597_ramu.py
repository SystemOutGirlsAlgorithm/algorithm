# 5597 : 과제 안 내신 분..?
import sys
result = [0] * 31
for i in range(28):
    result[int(sys.stdin.readline())] = 1

for i in range(1, 31):
    if result[i] == 0:
        print(i)
