a, b = map(int, input().split())

answer = []
# DFS로 문제 풀기
def solution(a, b, count) :
	# A와 B가 같으면 answer에 연산 횟수를 넣어준다.
    if a == b :
        answer.append(count)
    # A가 무조건 B보다 작아야 하므로 클 경우 생각 X
    elif a < b :
        count += 1
        # 2를 곱한 경우
        solution(a*2, b, count)
        # 1을 수의 가장 오른쪽에 추가한 경우
        solution(a*10+1, b, count)

solution(a, b, 0)

# answer에 값이 있으면 최솟값 +1 출력
if len(answer) > 0 :
    print(min(answer) + 1)
# answer에 값이 없다는 것은 만들 수 없는 경우
else :
    print(-1)