def solution(sizes):
    answer = 0
    le = []
    ri = []
    for size in sizes:
        le.append(sorted(size)[0])
        ri.append(sorted(size)[1])
    
    answer += max(le) * max(ri)
    
    return answer
