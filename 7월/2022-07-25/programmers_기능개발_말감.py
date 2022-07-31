def solution(progresses, speeds):
    answer = []
    while progresses :
        if progresses[0] >= 100 :
            progresses.pop(0)
            speeds.pop(0)
            answer.append(1)
            while progresses and progresses[0] >= 100 :
                progresses.pop(0)
                speeds.pop(0)
                answer[-1] += 1
            continue
        for i in range(len(progresses)) :
            progresses[i] += speeds[i]
    return answer