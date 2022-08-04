import pandas as pd

def solution(clothes):
    answer = 1
    cl_dict = {}
    clo = pd.DataFrame(clothes, columns = ['name', 'category'])
    
    for cate in list(set(clo['category'])):
        cl_dict[cate] = sum(clo['category']==cate)
    
    for bb in list(cl_dict.values()):
        answer *= bb+1
        
    answer -= 1
    
    return answer
