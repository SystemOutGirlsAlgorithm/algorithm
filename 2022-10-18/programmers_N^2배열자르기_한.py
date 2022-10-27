def solution(n, left, right):
    answer = []
    
    for i in range(left, right + 1):
        h = i // n
        w = i % n
        if h >= w:
            answer.append(h + 1)
        else:
            answer.append(w + 1)
    return answer

