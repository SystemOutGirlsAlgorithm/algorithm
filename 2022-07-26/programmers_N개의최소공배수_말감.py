def gcd(a, b) :
    max_num = max(a, b)
    min_num = min(a, b)
    while max_num % min_num != 0 :
        num = max_num % min_num
        max_num = min_num
        min_num = num
    return min_num

def solution(arr):
    answer = arr[0]
    for i in range(1, len(arr)) :
        number = gcd(answer, arr[i])
        answer = answer * arr[i] // number
    return answer