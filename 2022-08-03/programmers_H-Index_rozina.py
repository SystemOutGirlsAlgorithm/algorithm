import numpy as np


def solution(citations):
    kk = []
    for h in range(np.max(citations),-1,-1):
        a = np.sum(np.array(citations) >= h)
        b = len(citations) - a
        if (a >= h) and (b <= h): 
            answer = h
            break
    return answer
