import numpy as np


def solution(answers):
    answer = []
    first = [[1,2,3,4,5] for x in range(int(10000/5))]
    first1 = np.array(first).flatten()
    second = [[2,1,2,3,2,4,2,5] for y in range(int(10000/8))]
    second1 = np.array(second).flatten()
    third = [[3,3,1,1,2,2,4,4,5,5] for z in range(int(10000/10))]
    third1 = np.array(third).flatten()
    
    f = 0; s = 0; t = 0
    for kk in range(len(answers)):
        if first1[kk] == answers[kk]: f+=1
        if second1[kk] == answers[kk]: s+=1
        if third1[kk] == answers[kk]: t +=1
    
    if np.max([f, s, t]) == f: answer.append(1)
    if np.max([f, s, t]) == s: answer.append(2)
    if np.max([f, s, t]) == t: answer.append(3)
    
    answer = sorted(answer)
    return answer
