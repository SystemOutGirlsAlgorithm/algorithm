import sys
input = sys.stdin.readline
n, m = map(int, input().split())

card = list(map(int, input().split()))
card.sort()

for _ in range(m) :
    add = card[0] + card[1]
    card[0] = add
    card[1] = add
    card.sort()

print(sum(card))
