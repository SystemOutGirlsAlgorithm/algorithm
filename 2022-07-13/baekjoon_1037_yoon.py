n = int(input())
a = list(map(int, input().split()))

a_max = max(a)
a_min = min(a)

print(a_max*a_min)		#n의 약수 a의 최대,최소를 곱하면 n이 계산된다.
