def solution(absolutes, signs):
    answer = 0
    for i, absolute in enumerate(absolutes):
        if signs[i]:
            answer += absolute
        else:
            answer -= absolute
            
    return answer