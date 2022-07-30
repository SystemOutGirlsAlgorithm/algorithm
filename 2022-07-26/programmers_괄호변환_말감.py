def solution(p):
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if not p :
        return p
    # 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    check = True
    num = 0
    for i in range(len(p)) :
        num += 1 if p[i] == '(' else -1
        if num < 0 :
            check = False
        if num == 0 :
            num = i+1
            break
    u = p[:num]
    v = p[num:]
    # 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    if check :
        return u + solution(v)
    # 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
    # 4-1, 4-2, 4-3
    sol = solution(v)
    temp = '()' if not sol else '(' + sol + ')'
    # 4-4, 4-5
    for letter in u[1:len(u)-1] :
        temp += '(' if letter == ')' else ')'
    return temp    
    