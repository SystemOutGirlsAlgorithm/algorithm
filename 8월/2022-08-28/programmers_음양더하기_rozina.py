def solution(absolutes, signs):
    answer = 0
    for n in range(len(signs)):
        if signs[n] == False: answer -= absolutes[n]
        else: answer += absolutes[n]
    return answer
