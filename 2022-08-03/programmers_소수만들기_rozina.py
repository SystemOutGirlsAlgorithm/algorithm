import itertools
import numpy as np


def solution(nums):
    answer = 0
    ho = [aa[0]+aa[1]+aa[2] for aa in list(itertools.combinations(nums,3))]
    for h in ho:
        if np.sum([h%k==0 for k in range(1,h+1)]) == 2: answer += 1 
        
    return answer
