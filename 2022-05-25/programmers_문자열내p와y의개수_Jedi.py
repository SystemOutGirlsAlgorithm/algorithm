def solution(s):
    answer = False
    
    s = s.upper()
    
    if s.count('P') == s.count('Y'):
        answer = True

    return answer