def solution(array, commands):
    answer = []
    for command in commands:
        i, j, count = command
        temp = sorted(array[i-1:j])[count-1]
        answer.append(temp)
    return answer

solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]])