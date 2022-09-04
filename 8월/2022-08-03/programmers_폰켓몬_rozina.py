import pandas as pd

def solution(nums):
    answer = 0
    kk = pd.Series(nums).nunique()
    if kk <= len(nums)/2:
        answer += kk
    else: answer += len(nums)/2
    return answer
