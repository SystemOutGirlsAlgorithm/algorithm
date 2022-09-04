def solution(a, b):
    answer = 0
    for n in range(len(a)):
        answer += a[n]*b[n]
    return answer
