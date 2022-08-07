import sys
N = int(input())

students = list(list(map(int, sys.stdin.readline().split())) for _ in range(N * N))

classroom = [[0] * N for _ in range(N)] # 최종 정해진 자리

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
fixed = []  # 정해진 자리 (다른 학생을 앉힐 수 없는 자리)

# 첫 번째 조건 : 좋아하는 학생이 주위에 가장 많은 자리 선택
def condition1(like):
    maxf = 0    # 주위 좋아하는 학생 수
    best = []   # 자리 후보 (조건 2로 넘기기 위해 list로 설정)

    # 모든 자리 확인
    for i in range(N):
        for j in range(N):
            cnt = 0 # 자리마다 주위에 좋아하는 학생 수가 몇 명인지 확인
            for (dr, dc) in dir:
                nr, nc = i + dr, j + dc
                if 0 <= nr < N and 0 <= nc < N and classroom[nr][nc] != 0:
                    for friend in like: # 주위에 좋아하는 학생이 있으면 cnt + 1
                        if classroom[nr][nc] == friend:
                            cnt += 1
            if (i, j) not in fixed: # 자리가 아직 비어있을 때
                if cnt > maxf:  # 현재 자리에 주변에 좋아하는 학생 수가 가장 많으면
                    maxf = cnt
                    best = [(i, j)]
                elif cnt == maxf:   # 자리 후보
                    best.append((i, j))
                if cnt == 4:    # 주변이 모두 좋아하는 학생이면 이 자리가 최선
                    return [(i, j)]
    return best

# 조건 2 : 주변에 빈 자리가 가장 많은 경우
def condition2(betters):
    maxSpace = 0    # 주변 빈 자리 수
    best = [] 
    for better in betters:  # 자리 후보마다 확인하기
        i, j = better
        if classroom[i][j] != 0:    # 자리 후보에 이미 다른 학생을 앉혔다면
            continue    # 다음 자리 후보 확인
        cnt = 0     # 빈 자리 count
        for (dr, dc) in dir:
            nr, nc = i + dr, j + dc
            if 0 <= nr < N and 0 <= nc < N and classroom[nr][nc] == 0:  # 주변 자리가 비어있으면 cnt + 1
                cnt += 1         
        if cnt > maxSpace:  # 현재 자리 주변이 가장 많이 비어있으면
            maxSpace = cnt  # 자리 후보 교체
            best = [(i, j)]
        elif cnt == maxSpace:   # 자리 후보에 추가
            best.append((i, j))   
        if cnt == 4:    # 주변이 모두 비어있으면
            return [(i, j)] # 그 자리를 선택
    if len(best) == 0:  # 만약 마지막 자리 하나만 남았다면
        for i in range(N):
            for j in range(N):
                if (i, j) not in fixed:
                    best = [(i, j)] # 그 자리를 선택
    return best

for studentInfo in students:
    student = studentInfo[0]
    like = studentInfo[1:]
    best1 = condition1(like)
    if len(best1) == 1: # 첫 번째 조건을 만족하는 자리가 하나라면
        (r, c) = best1[0]   # 그 자리 선택
        classroom[r][c] = student
        fixed.append((r, c))    # 정해진 자리에 추가
    else:   # 첫 번째 조건을 만족하는 자리가 여러 개면
        best2 = condition2(best1)   # 두 번째 조건 확인
        (r, c) = best2[0]   # 두 번째 조건을 만족하는 자리에 앉힘
        classroom[r][c] = student
        fixed.append((r, c))    # 정해진 자리에 추가

scores = 0  # 점수 확인을 위해 모든 학생들의 자리를 확인
for i in range(N):
    for j in range(N):
        score = 0   # 현재 학생의 점수
        for dr, dc in dir:
            nr, nc = i + dr, j + dc
            if 0 <= nr < N and 0 <= nc < N:
                around = classroom[nr][nc]
                likes = list(filter(lambda student: student[0] == classroom[i][j], students))
                if around in likes[0][1:]:  # 주위 4자리에 좋아하는 학생이 있으면 score + 1
                    score += 1
        if score != 0:  # 주변에 좋아하는 학생이 1명 이상이면
            scores += 10 ** (score-1)   # 점수 추가

print(scores)