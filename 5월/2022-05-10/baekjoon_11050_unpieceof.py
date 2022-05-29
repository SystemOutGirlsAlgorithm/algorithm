# 11050. 이항 계수 1
def factorial(num):
	result = 1
	for i in range(num):
		result*=(num - i)
	return result

n, k = map(int, input().split())
print(factorial(n)//(factorial(k)*factorial(n-k))) # 재귀적으로 푸는 방법도 고민해보기
