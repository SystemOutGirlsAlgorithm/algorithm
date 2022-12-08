def solution(array):
    array.sort()
    answer = 0
    array_l = len(array)//2
    answer = array[array_l]
    return answer
