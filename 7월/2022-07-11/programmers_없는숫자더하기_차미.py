def solution(numbers):
    answer = 0
    check = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for number in check:
        if not number in numbers:
            answer += number

    return answer