import math

def solution(progresses, speeds):
    answer = []
    t = [math.ceil((100-progresses[k])/speeds[k]) for k in range(len(progresses))]
    
    while t:
        ind = t.index(max(t))
        answer.append(len(t[ind:]))
        t = t[:ind]
        
    answer = answer[::-1]
    return answer
