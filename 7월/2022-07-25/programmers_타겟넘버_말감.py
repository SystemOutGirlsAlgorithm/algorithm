def targetNumber(i, answer, numbers, target, temp) :
    if i == len(numbers):
        if temp == target :
            answer.append(target)
        return
    targetNumber(i+1, answer, numbers, target, temp + numbers[i])
    targetNumber(i+1, answer, numbers, target, temp - numbers[i])

def solution(numbers, target):
    answer = []
    temp = 0
    targetNumber(0, answer, numbers, target, temp)
    return len(answer) 