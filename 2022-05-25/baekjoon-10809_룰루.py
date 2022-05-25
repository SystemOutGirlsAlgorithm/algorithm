S = list(input())
alpa = []

for i in range(26):
    alpa.append(-1)

for i in range(len(S)):
    if alpa[ord(S[i])-97]==-1:
        alpa[ord(S[i])-97] = i

for i in range(len(alpa)):
    print(alpa[i], end=" ")
