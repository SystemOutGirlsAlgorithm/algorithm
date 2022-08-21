def solution(arr):
    answer = []
    answer.append(arr[0])
    for num in range(1,len(arr)):
        if arr[num] == arr[num-1]:
            pass
        elif arr[num] != arr[num-1]:
            answer.append(arr[num])
    return answer
