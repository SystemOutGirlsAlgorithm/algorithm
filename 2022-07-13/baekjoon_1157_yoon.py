word = input().lower()
word_list = list(set(word))	#set은 순서X, 중복X인 자료형이다.
cnt = []

for i in word_list:	#중복제거한 word_list에서 변수i 생성
    count = word.count(i)	#count(i)-리스트 내의 요소i의 개수를 반환하는 함수
    cnt.append(count)	#각 문자의 총 개수에 대한 값을 리스트 cnt에 각각 추가

if cnt.count(max(cnt))>=2:	#동일한 max값이  2개 이상 존재한다면 ?출력
    print("?")
else:
    print(word_list[(cnt.index(max(cnt)))].upper())		#max인 값을 word_list에서 찾아 대문자로 출력
