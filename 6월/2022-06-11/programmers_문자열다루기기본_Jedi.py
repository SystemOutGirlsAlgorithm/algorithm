def solution(s):
    answer = False

    if (len(s) == 4) or (len(s) == 6):
        answer = True
    
    try:
        num = int(s)
    except ValueError:
        answer = False

    
    return answer