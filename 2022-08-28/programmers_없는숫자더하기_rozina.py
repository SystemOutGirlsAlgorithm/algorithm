def solution(numbers):
    num_list = [0,1,2,3,4,5,6,7,8,9]
    for num in numbers:
        num_list.remove(num)
    answer = sum(num_list)
    return answer
