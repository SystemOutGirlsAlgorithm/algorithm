import sys
input = sys.stdin.readline

k = int(input())

s = format(k+1, 'b')
s = s[1:]

print(s.replace('0', '4').replace('1', '7'))
