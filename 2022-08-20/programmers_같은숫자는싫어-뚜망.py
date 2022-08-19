def solution(arr):
    answer = []
    answer.append(arr[0])

    for a in arr[1:]:
        if a != answer[-1]:
            answer.append(a)

    return answer

