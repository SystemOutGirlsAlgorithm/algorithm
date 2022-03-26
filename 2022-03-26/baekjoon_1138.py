import sys
input = sys.stdin.readline

n = int(input())

info = list(map(int, input().split()))

line = [-1] * n
# 키가 제일 작은 사람 먼저 넣어주기
# 자기보다 키가 큰 사람의 수가 키가 가장 작은 사람의 위치(인덱스)이다.
line[info[0]] = 1

# 사람 키 순서대로
for i in range(1, n) :
    count = 0
    # line의 인덱스
    for j in range(n) :
    	# 비어있지 않으면 어차피 못들어가므로 셀 필요 X
        if line[j] != -1 :
            continue
        # 비어있는 칸의 수와 자신보다 큰 사람의 수가 같을 경우 넣어주기
        if count == info[i] :
            line[j] = i+1
            break
        else :
            count += 1
print(*line)