from collections import deque

n = int(input())
card = deque()
for i in range(1, n+1) :
    card.append(i)
i = 1
while len(card) > 1 :
    tmp = card.popleft()
    if i % 2 == 0 :
        card.append(tmp)
    i+=1
    
print(*card)