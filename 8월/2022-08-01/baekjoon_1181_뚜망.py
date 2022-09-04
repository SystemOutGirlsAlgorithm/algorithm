import sys
input = sys.stdin.readline

N = int(input())
S = {input().strip() for _ in range(N)}
S = sorted(list(S))
S.sort(key=lambda x: len(x))
print('\n'.join(S))
