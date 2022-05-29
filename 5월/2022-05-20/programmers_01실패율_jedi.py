def solution(N, stages):
    answer = []
    fail = []
    
    for i in range(1, (N)+1):
        div = 0
        for j in stages:
            if j >= i:
                div += 1
        if stages.count(i) > 0:
            fail.append((stages.count(i)/div, i))
        else:
            fail.append(0)
    
    fail = sorted(fail, key=lambda x: -x[0])
    
    for i in fail:
        answer.append(i[1])
    
    return answer

print(solution(4, [4, 4, 4, 4, 4]))