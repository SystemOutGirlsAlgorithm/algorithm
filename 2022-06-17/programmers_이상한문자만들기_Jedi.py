def solution(s):
    answer = ''
    count = 0
    
    for i in range(len(s)):
        if s[i] == ' ':
            count = 0
            answer += ' '
        else:
            if count%2 == 0:
                answer += s[i].upper()
            else:
                answer += s[i].lower()
            count += 1
    
    return answer