def solution(priorities, location):
    st = list(range(len(priorities)))
    st_dict = {}
    
    num = 1
    while priorities:
        m = max(priorities)
        ind = priorities.index(m)
        st_dict[f'{st[ind]}'] = num
        st = st[ind+1:] + st[:ind]
        priorities = priorities[ind+1:] + priorities[:ind]
        num += 1
        
    answer = st_dict[f'{location}']
    return answer
