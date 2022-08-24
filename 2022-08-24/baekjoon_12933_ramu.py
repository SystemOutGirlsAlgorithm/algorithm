# 12933 : 오리
import sys

cry = {'q': 0, 'u': 1, 'a': 2, 'c': 3, 'k': 4}

crying = list(input())
ducks = []
num = 0
end = False

for ch in crying:
    if ch == 'q':
        # 처음 시작
        if num == 0:
            ducks.append([ch])
            num += 1
        # 오리가 있으면
        else:
            for i in range(num):
                if ducks[i][-1] == 'k':
                    ducks[i].append(ch)
                    break
                if i == num - 1:
                    ducks.append([ch])
                    num += 1
                    break
    else:
        if num == 0:
            end = True
            break
        else:
            for i in range(num):
                if cry[ch] == cry[ducks[i][-1]] + 1:
                    ducks[i].append(ch)
                    break
                if i == num - 1:
                    end = True
                    break
for duck in ducks:
    if duck[-1] != 'k':
        end = True
        break

if end:
    print(-1)
else:
    print(num)