import sys
input = sys.stdin.readline

# 사진틀
n = int(input())

# 총 추천 횟수
re = int(input())

# 학생의 추천 결과
stu = list(map(int, input().split()))

# 딕셔너리를 이용한다. {학생 : [횟수, 순서]}
photo = dict()
for i in range(re) :
    # 사진틀 안에 사진이 있다면
    if stu[i] in photo :
        # 추천 횟수만 증가
        photo[stu[i]][0] += 1
    # 사진틀 안에 사진이 없다면
    else :
        # 비어있는 사진틀이 없을 때
        if len(photo) >= n :
            # 추천 받은 횟수, 게시된 순서로 정렬
            # 추천 받은 횟수가 적고 오래 게시된 사진이 맨 앞에 오게 됨
            tmp_photo = sorted(photo.items(), key=lambda x:(x[1][0], x[1][1]))
            # 맨 첫번째 사진을 지운다.
            del photo[tmp_photo[0][0]]
        # 사진틀에 게시한다.
        photo[stu[i]] = [1, i]
# 증가하는 순서대로 정렬            
answer = sorted(photo.keys())
print(*answer)