#baekjoon_2217_jedi
#Greedy

n = int(input())
lope = [int(input()) for i in range(n)]
height = []

lope.sort()
lope.reverse()

for i in range(0, len(lope)):
    height.append(lope[i]*(i+1))

print(max(height))