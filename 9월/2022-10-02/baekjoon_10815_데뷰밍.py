from collections import Counter

n = int(input())
card = list(map(int, input().split()))
card_dic = Counter(card)

m = int(input())
card2 = list(map(int, input().split()))
result = [0] * m

for i, c in enumerate(card2):
    if card_dic.get(c, 0) != 0:
        result[i] = 1

for r in result:
    print(r, end=' ')