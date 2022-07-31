#baekjoon_1546_yoon.py

n = int(input())	#과목개수 n
score_list = list(map(int,input().split()))	#과목 점수들이 저장된 리스트 score_list
max_score = max(score_list)	#점수들 중 가장 높은 점수 max_score

new_list = []
for score in score_list:	#원래 점수들이 저장된 리스트 score_list에서 점수 score
    new_list.append(score/max_score*100)	#새 리스트 new_list에 조작된 값을 추가한다.
avg = sum(new_list)/n	#조작된 점수들의 평균 avg
print(avg)
