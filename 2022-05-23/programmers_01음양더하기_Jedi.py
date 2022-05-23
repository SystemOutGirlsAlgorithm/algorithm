def solution(absolutes, signs)
    answer = 0
    
    for num in range(len(absolutes))
        if signs[num]
            answer += absolutes[num]
        else
            answer -= absolutes[num]
    
    return answer