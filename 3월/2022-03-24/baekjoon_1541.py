n = input()

tmp = ''
change = []
# 숫자와 연산 기호를 분리시켜 하나의 배열로 만들었다.
# str(int(tmp))로 앞이 0으로 시작하는 숫자를 모두 일반 자연수로 만들어 줌
for i in n :
    if i.isdigit() :
        tmp += i
    else :
        change.append(str(int(tmp)))
        change.append(i)
        tmp = ''
# 마지막 숫자를 넣어주는 부분
if tmp != '' :
    change.append(str(int(tmp)))

check = ''
answer = []
for p in range(len(change)) :
	# 숫자면 배열에 넣기
    if change[p].isdigit() :
        answer.append(change[p])
    else :
        # -가 나오면 괄호 시작
        if change[p] == '-' :
        	# -가 연속해서 나올 수 있으므로 '('가 있는 경우 닫아주고 다시 새로 '('를 넣는다.
            if '(' in answer :
                answer.append(')')
            answer.append(change[p])
            answer.append('(')
            check = 'open'
        # +는 그냥 넣어준다.
        else :
            answer.append(change[p])

#맨 마지막 숫자가 괄호로 묶여있을 수 있으므로 확인
if check != '' :
    answer.append(')')

# eval() 함수를 이용해서 계산
print(eval(''.join(answer)))